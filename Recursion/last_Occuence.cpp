#include <iostream>
#include <vector>
using namespace std;

int lastOcc(vector<int> arr, int i, int target){
  if( i == arr.size()){
    return -1;
  }
  if(arr[i] == target){
    return i;
  }
  return lastOcc(arr, i+1, target);
}

int main(){
  vector<int> arr = {1, 2, 3, 4, 3};

  cout << lastOcc(arr, 0, 3);
  return 0;
}