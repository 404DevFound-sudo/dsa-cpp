#include <iostream>
using namespace std;

int main(){
  
  int matrix[4][4] = {{1, 2, 3, 4},
                      {5, 6, 7, 8}
};

  int rows = 2;
  int cols = 4;

  //create transpose matrix
  int transpose[cols][rows];

  //fill transpose matrix
  for(int i=0 ; i<rows; i++){
    for(int j=0; j<cols ; j++){
      transpose[j][i] = matrix[i][j]; 
    }
  }
  
  //print original matrix
  cout << "original matrix" <<endl;
    for(int i=0 ; i<rows; i++){
    for(int j=0; j<cols ; j++){
      cout << matrix[i][j] <<" ";
    }
    cout << endl;
  }
  cout << endl;

  //print transpose matrix
  cout <<"Transpose matrix"<< endl;
   for(int i=0 ; i<cols; i++){
    for(int j=0; j<rows ; j++){
      cout << transpose[i][j] <<" "; 
    }
    cout << endl;
  }
  cout << endl;
 
  return 0;
}