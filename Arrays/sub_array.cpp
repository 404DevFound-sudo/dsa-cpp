#include <iostream>
using namespace std;

void printArr(int arr[],int n){
   for(int i = 0; i<n ; i++){
    cout << arr[i] << ", ";
}
}

void subarray(int arr[], int n){
  for(int i=0 ; i<n; i++){
    for(int j=i; j<n; j++){
      for(int k=i; k<=j;k++){
        cout<<arr[k];
      }
      cout<<",";
    }
    cout<<endl;
  }
}


int main(){
  int arr[] = {1,2, 3, 4, 5};
  int n= sizeof(arr)/sizeof(int);
  int key = 7;
  
   
  //printArr(arr, n);
  subarray(arr, n);
  return 0;
}