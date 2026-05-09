#include <iostream>
#include <string.h>
using namespace std;


class User{
  private:
    int id;
    string password;

  public:
   string username;

    User(int id){
      this->id = id;
    }
    //getter
    string getPassword(){
      return password;
    }

    //setter
    void setPassword(string password){
      this->password = password;
    }
};

int main(){
  User user1(101);
  user1.username = "rohit";
  user1.setPassword("skdhf");

  cout << "username = "<<user1.username<< endl;
  cout << "password = "<<user1.getPassword() <<endl;

 
  return 0;
}