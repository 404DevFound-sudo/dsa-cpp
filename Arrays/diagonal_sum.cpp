#include <iostream>
using namespace std;

void diagonalSum(int mat[][4], int n, int m){
  int sum = 0;

  for(int i = 0; i<n; i++){//rows
    for (int j = 0 ; j<n; j++){// columns
      if(i == j){
        sum+= mat[i][j];
      }
      else if(j == n - i -1){
        sum+= mat[i][j];
      }
    }
  }
  cout << "sum is = "<<sum;
}


int main(){
  
  int matrix[4][4] = {{1, 2, 3, 4},
                      {5, 6, 7, 8},
                      {9, 10, 11, 12},
                      {13, 14, 15, 16}
};
int n = 4;
int m = 4;
  
   
  diagonalSum(matrix,n,m);
  return 0;
}