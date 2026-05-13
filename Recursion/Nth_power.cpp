#include <iostream>
#include <vector>
using namespace std;

int pow(int x, int n){ //O(logn) TC
if(n == 0){
  return 1;
}
  int halfPow = pow(x, n/2);
  int halfPowSquare = halfPow * halfPow;

  if(n % 2 != 0){
    return x * halfPowSquare;
  }
    return halfPowSquare;

}

int main(){
  
  int x = 2;
  cout << pow(x, 4);
  cout << pow(x, 5);

  return 0;
}