#include <iostream>
#include <string.h>
using namespace std;

  
void toLower(char word[], int n){
  for(int i=0 ; i<n; i++){
    char ch = word[i];
    if(ch>='a' && ch<='z'){
      continue;
    }else{ 
        word[i] = ch - 'A' + 'a';
    }
  }
}

int main(){
  char word[] = "BANANA";

 toLower(word, strlen(word));
  cout << "the word is = "<<word <<endl;
  cout <<"the size is = "<<strlen(word)<< endl;
  return 0;
}