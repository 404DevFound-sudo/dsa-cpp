#!/usr/bin/env python3
"""
Fingertip Object Control
Move objects on screen by tracking your fingertips using a webcam
"""
 
import cv2
import mediapipe as mp
import numpy as np
import math

class MovableObject:
    """Represents an object that can be moved by fingertip"""
    def __init__(self, x, y, radius=30, color=(0, 255, 0), label="Object"):
        self.x = x
        self.y = y
        self.radius = radius
        self.color = color
        self.label = label
        self.is_grabbed = False
        self.grab_offset_x = 0
        self.grab_offset_y = 0
    
    def draw(self, frame):
        """Draw the object on the frame"""
        # Draw circle
        cv2.circle(frame, (int(self.x), int(self.y)), self.radius, self.color, -1)
        # Draw border
        border_color = (255, 255, 255) if self.is_grabbed else (0, 0, 0)
        cv2.circle(frame, (int(self.x), int(self.y)), self.radius, border_color, 2)
        # Draw label
        cv2.putText(frame, self.label, (int(self.x - 20), int(self.y - self.radius - 10)),
                   cv2.FONT_HERSHEY_SIMPLEX, 0.5, self.color, 2)
    
    def is_point_inside(self, px, py):
        """Check if a point is inside the object"""
        distance = math.sqrt((px - self.x)**2 + (py - self.y)**2)
        return distance <= self.radius
    
    def grab(self, finger_x, finger_y):
        """Grab the object at the finger position"""
        self.is_grabbed = True
        self.grab_offset_x = self.x - finger_x
        self.grab_offset_y = self.y - finger_y
    
    def move(self, finger_x, finger_y):
        """Move the object to follow the finger"""
        if self.is_grabbed:
            self.x = finger_x + self.grab_offset_x
            self.y = finger_y + self.grab_offset_y
    
    def release(self):
        """Release the object"""
        self.is_grabbed = False


class FingertipObjectController:
    def __init__(self):
        # Initialize MediaPipe Hands
        self.mp_hands = mp.solutions.hands
        self.hands = self.mp_hands.Hands(
            static_image_mode=False,
            max_num_hands=2,
            min_detection_confidence=0.7,
            min_tracking_confidence=0.5
        )
        self.mp_draw = mp.solutions.drawing_utils
        
        # Initialize camera
        self.cap = cv2.VideoCapture(0)
        self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, 1280)
        self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 720)
        
        # Create movable objects
        self.objects = [
            MovableObject(300, 300, 40, (255, 100, 100), "Red"),
            MovableObject(600, 300, 40, (100, 255, 100), "Green"),
            MovableObject(900, 300, 40, (100, 100, 255), "Blue"),
            MovableObject(450, 500, 40, (255, 255, 100), "Yellow"),
            MovableObject(750, 500, 40, (255, 100, 255), "Magenta"),
        ]
        
        # Track finger states
        self.prev_pinch_states = {}  # Track pinch state per hand
        
    def is_pinching(self, hand_landmarks, handedness):
        """Detect if thumb and index finger are pinching"""
        # Get thumb tip and index finger tip
        thumb_tip = hand_landmarks.landmark[self.mp_hands.HandLandmark.THUMB_TIP]
        index_tip = hand_landmarks.landmark[self.mp_hands.HandLandmark.INDEX_FINGER_TIP]
        
        # Calculate distance between thumb and index finger
        distance = math.sqrt(
            (thumb_tip.x - index_tip.x)**2 + 
            (thumb_tip.y - index_tip.y)**2
        )
        
        # Threshold for pinch detection (adjust as needed)
        return distance < 0.05
    
    def get_index_finger_position(self, hand_landmarks, frame_shape):
        """Get the index finger tip position in pixel coordinates"""
        index_tip = hand_landmarks.landmark[self.mp_hands.HandLandmark.INDEX_FINGER_TIP]
        h, w, _ = frame_shape
        x = int(index_tip.x * w)
        y = int(index_tip.y * h)
        return x, y
    
    def run(self):
        """Main application loop"""
        print("Fingertip Object Controller")
        print("=" * 50)
        print("Controls:")
        print("- Pinch (thumb + index finger) to grab objects")
        print("- Move your hand while pinching to move objects")
        print("- Release pinch to drop objects")
        print("- Press 'q' to quit")
        print("- Press 'r' to reset object positions")
        print("=" * 50)
        
        while True:
            success, frame = self.cap.read()
            if not success:
                print("Failed to read from camera")
                break
            
            # Flip frame horizontally for mirror effect
            frame = cv2.flip(frame, 1)
            h, w, _ = frame.shape
            
            # Convert to RGB for MediaPipe
            rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
            results = self.hands.process(rgb_frame)
            
            # Draw all objects
            for obj in self.objects:
                obj.draw(frame)
            
            # Process hand landmarks
            if results.multi_hand_landmarks and results.multi_handedness:
                for hand_idx, (hand_landmarks, handedness) in enumerate(
                    zip(results.multi_hand_landmarks, results.multi_handedness)
                ):
                    # Draw hand landmarks
                    self.mp_draw.draw_landmarks(
                        frame, hand_landmarks, self.mp_hands.HAND_CONNECTIONS
                    )
                    
                    # Get hand label (Left/Right)
                    hand_label = handedness.classification[0].label
                    
                    # Get index finger position
                    finger_x, finger_y = self.get_index_finger_position(hand_landmarks, frame.shape)
                    
                    # Draw fingertip indicator
                    cv2.circle(frame, (finger_x, finger_y), 10, (0, 255, 255), -1)
                    cv2.circle(frame, (finger_x, finger_y), 12, (255, 255, 255), 2)
                    
                    # Check pinch gesture
                    is_pinching_now = self.is_pinching(hand_landmarks, handedness)
                    was_pinching = self.prev_pinch_states.get(hand_label, False)
                    
                    # Handle pinch state changes
                    if is_pinching_now and not was_pinching:
                        # Just started pinching - try to grab an object
                        for obj in self.objects:
                            if obj.is_point_inside(finger_x, finger_y) and not obj.is_grabbed:
                                obj.grab(finger_x, finger_y)
                                break
                    
                    elif not is_pinching_now and was_pinching:
                        # Just released pinch - release any grabbed objects
                        for obj in self.objects:
                            if obj.is_grabbed:
                                obj.release()
                    
                    elif is_pinching_now:
                        # Currently pinching - move grabbed objects
                        for obj in self.objects:
                            if obj.is_grabbed:
                                obj.move(finger_x, finger_y)
                    
                    # Update pinch state
                    self.prev_pinch_states[hand_label] = is_pinching_now
                    
                    # Display hand status
                    status = "PINCHING" if is_pinching_now else "OPEN"
                    cv2.putText(frame, f"{hand_label}: {status}", (10, 30 + hand_idx * 30),
                              cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)
            
            # Display instructions
            cv2.putText(frame, "Press 'q' to quit | 'r' to reset", 
                       (10, h - 20), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)
            
            # Show frame
            cv2.imshow('Fingertip Object Controller', frame)
            
            # Handle keyboard input
            key = cv2.waitKey(1) & 0xFF
            if key == ord('q'):
                break
            elif key == ord('r'):
                # Reset object positions
                self.objects = [
                    MovableObject(300, 300, 40, (255, 100, 100), "Red"),
                    MovableObject(600, 300, 40, (100, 255, 100), "Green"),
                    MovableObject(900, 300, 40, (100, 100, 255), "Blue"),
                    MovableObject(450, 500, 40, (255, 255, 100), "Yellow"),
                    MovableObject(750, 500, 40, (255, 100, 255), "Magenta"),
                ]
                print("Objects reset to original positions")
        
        # Cleanup
        self.cap.release()
        cv2.destroyAllWindows()
        self.hands.close()


if __name__ == "__main__":
    try:
        controller = FingertipObjectController()
        controller.run()
    except KeyboardInterrupt:
        print("\nApplication stopped by user")
    except Exception as e:
        print(f"Error: {e}")
        import traceback
        traceback.print_exc()