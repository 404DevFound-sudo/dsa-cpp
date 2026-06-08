#include <iostream>
#include <string>
#include <vector>
using namespace std;

int partition(int arr[],int si, int ei){
  int i = si -1;
  int pivot = arr[ei];

  for(int j = si; j<ei; j++){
    if(arr[j] <= pivot){
      i++;
      swap(arr[i],arr[j]);
    }
  }
  i++;
  swap(arr[i],arr[ei]);

  return i;

}

void quickSort(int arr[], int si, int ei){
  if(si >= ei){
    return;
  }
  int pivetIdx = partition(arr, si , ei);
  quickSort(arr, si, pivetIdx-1);
  quickSort(arr, pivetIdx+1, ei);

}

void printArr(int arr[],int n){
  for(int i=0; i<=n; i++){
    cout<< arr[i] << "\t";
  }
}

int main(){
  int arr[] = {9, 8, 7, 6, 5, 4, 2, 3, 1, 10};

  quickSort(arr, 0, 9);
  printArr(arr,9);
  return 0;
}
