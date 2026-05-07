#include <iostream>
using namespace std;

void printArr(int arr[],int n){
   for(int i = 0; i<n ; i++){
    cout << arr[i] << ", ";
}
}

void subarray_sum(int arr[], int n){
  int maxsum = INT_FAST16_MIN;
  int currSum = 0;
  for(int i=0 ; i<n; i++){
      currSum += arr[i];
      maxsum = max(maxsum, currSum);

      if(currSum < 0){
        currSum = 0;
      }
    }
   
  cout << "maximum of the sum is = "<<maxsum;
}


int main(){
  int arr[] = {1,2, 3, 4, 5};
  int n= sizeof(arr)/sizeof(int);
  int key = 7;
  
   
  //printArr(arr, n);
  subarray_sum(arr, n);
  return 0;
}