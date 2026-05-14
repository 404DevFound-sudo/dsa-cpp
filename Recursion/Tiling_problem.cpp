#include <iostream>
using namespace std;

int tilingProblem(int n){ //2*n
   
  if(n==1 || n==0){
   return 1;
  }
  //vertical 
  int ans1 = tilingProblem(n-1); //2 * n - 1
  //horizontal
  int ans2 = tilingProblem(n-2);  //2 * n - 2

  return ans1 + ans2;
 
}

int main(){
  int n;
 cout<< " enter number you want to find fibonacci number "<< endl;
 cin>>n;
 cout << tilingProblem(n);
  return 0;
}