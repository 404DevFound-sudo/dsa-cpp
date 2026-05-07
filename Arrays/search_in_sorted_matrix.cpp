#include <iostream>
using namespace std;

bool searchSortedmat(int mat[][4], int n, int m, int key){
  int i = 0,j = m-1;

  while(i < n && j >= 0){
    if(mat[i][j] == key){
      cout << "found at cell = ("<< i << ","<< j << ")";
      return true;
    }
    else if(mat[i][j] > key){
      //left
      j--;
    }
    else{
      //down
      i++;
    }
  }
  cout << "not found ";
  return false;
}


int main(){
  
  int matrix[4][4] = {{1, 2, 3, 4},
                      {5, 6, 7, 8},
                      {9, 10, 11, 12},
                      {13, 14, 15, 16}
};
int n = 4;
int m = 4;
  
   
 searchSortedmat(matrix,4,4,15);
  return 0;
}