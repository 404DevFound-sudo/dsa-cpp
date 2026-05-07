#include <iostream>
using namespace std;

void countOcurrences(int mat[][4], int n, int m, int target){
  int count = 0;
  
  // check every element in 2d array
  for(int i = 0; i<n ; i++){
    for(int j = 0; j<m ; j++){
      if(mat[i][j] == target){
        count++;
      }
    }
  }
  cout << " the count is of "<<target << " is "<<count;

}


int main(){
  
  int matrix[4][4] = {{1, 2, 3, 4},
                      {5, 6, 7, 8},
                      {9, 7, 11, 12},
                      {13, 14, 15, 7}
};
int n = 4;
int m = 4;
  
   
  countOcurrences(matrix,n,m,7);
  return 0;
}