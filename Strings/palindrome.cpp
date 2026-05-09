#include <iostream>
#include <string.h>
using namespace std;

  
bool palindrome(char word[], int n){
 int st = 0, end = n-1;
 while(st<end){
  if(word[st] != word[end]){
    cout << "not valid palindrome \n";
    return false;
  }
  st++;end--;
 }
 cout << "valid palindrome !";
 return true;
}

int main(){
 char word[] = "racecar";
 palindrome(word, strlen(word));
  return 0;
}