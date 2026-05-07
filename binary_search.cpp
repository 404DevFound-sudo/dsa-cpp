#include <iostream>
using namespace std;

void printArr(int arr[],int n){
   for(int i = 0; i<n ; i++){
    cout << arr[i] << ", ";
}
}
int binarySear(int arr[], int n,int key){
   int st= 0, end = n-1;

   while (st <= end){
    int mid = (st + end)/2;
    if(arr[mid] == key){
      return mid;
    }
     else if(arr[mid] > key){
      end = mid - 1;
     }
     else {
      st = mid + 1;
     }
   }
   return -1;

}

int main(){
  int arr[] = {1,2, 3, 4, 5, 6, 7, 8, 9, 10};
  int n= sizeof(arr)/sizeof(int);
  int key = 7;
  
   
  printArr(arr, n);
  cout << binarySear(arr, n, key);

  return 0;
}