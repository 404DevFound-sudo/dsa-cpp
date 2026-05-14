#include <iostream>
#include <string>
using namespace std;

void removeDuplicates(string str, string ans, int map[26],int i){
 
  if(i == str.size()){
    cout << "ans = "<<ans<<endl;
    return;
  }
  
  int mapIndx = (int)(str[i] - 'a');

  if(map[mapIndx]){//duplicate
    removeDuplicates(str, ans, map, i+1);
  }else{
    map[mapIndx] = true;
    removeDuplicates(str, ans+str[i], map, i+1);
    //non-duplicate
  }
}

int main(){
  string str = "appnnacollege";
  string ans = "";
  int map[26] ={false};
  cout<< "The string is = "<< str <<endl;

  removeDuplicates(str, ans, map, 0);
  return 0;
}