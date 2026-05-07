#include <iostream>
#include <string.h>
using namespace std;

  
void toUpper(char word[], int n){
  for(int i=0 ; i<n; i++){
    char ch = word[i];
    if(ch>='A' && ch<='Z'){//uppercase
      continue;
    }else{ //lowercase
        word[i] = ch - 'a' + 'A';
    }
  }
}

int main(){
  char word[] = "AppLe";

 toUpper(word, strlen(word));
  cout << "the word is = "<<word <<endl;
  cout <<"the size is = "<<strlen(word)<< endl;
  return 0;
}