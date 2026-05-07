#include <iostream>
using namespace std;

void printSum(int mat[][4], int n, int m ){
  int sum = 0;
  
  // sum of only second row
  for(int i = 1; i<2 ; i++){
    for(int j = 0; j<m ; j++){
      sum+= mat[i][j];
    }
  }
  cout << " the sum is of second row "<<"is "<<sum;

}


int main(){
  
  int matrix[4][4] = {{1, 2, 3, 4},
                      {5, 6, 7, 8},
                      {9, 7, 11, 12},
                      {13, 14, 15, 7}
};
int n = 4;
int m = 4;
  
   
  printSum(matrix,n,m);
  return 0;
}