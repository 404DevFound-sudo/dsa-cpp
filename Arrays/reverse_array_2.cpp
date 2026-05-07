#include <iostream>
using namespace std;

void printArr(int arr[],int n){
   for(int i = 0; i<n ; i++){
    cout << arr[i] << ", ";
}
}
// void swapArr(int arr[],int n){
// int start = 0,end = n-1;

// while(start <= end){
//   swap(start , end);
//   start++;
//   end--;
// }
// }

int main(){
  int arr[] = {1,2, 3, 4, 5, 6, 7, 8, 9, 10};
  int n= sizeof(arr)/sizeof(int);

    int start = 0,end = n-1,temp;

  while(start < end ){
  temp = arr[start];
  arr[start] = arr[end];
  arr[end] = temp;
  //swap(start,end);
  start++;
  end--;
}


  printArr(arr, n);

  return 0;
}