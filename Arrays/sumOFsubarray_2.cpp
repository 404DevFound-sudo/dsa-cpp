#include <iostream>
using namespace std;

void printArr(int arr[],int n){
   for(int i = 0; i<n ; i++){
    cout << arr[i] << ", ";
}
}

void subarray(int arr[], int n){
  int maxsum = INT_FAST16_MIN;
  for(int i=0 ; i<n; i++){
    int currSum = 0;
    for(int j=i; j<n; j++){
       currSum += arr[j];
      maxsum = max(maxsum, currSum);
    }
  }
  cout << "maximum of the sum is = "<<maxsum;
}


int main(){
  int arr[] = {1,2, 3, 4, 5};
  int n= sizeof(arr)/sizeof(int);
  int key = 7;
  
   
  //printArr(arr, n);
  subarray(arr, n);
  return 0;
}