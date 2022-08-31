#include <iostream>
#include <fstream> 
#include <string.h>
using namespace std;

bool LoggedIn(){
  string userID, password, ui, pd;
  
  cout<<"Enter user ID: "<<endl; cin>> userID;
  cout<<"Enter password: "<<endl; cin>> password;

  ifstream read("data\\" + userID + ".txt");
  getline(read, ui);
  getline(read, pd);

  if (ui == userID && pd == password){
    return true;
  }else{
    return false;
  }
    
}

int main(){
  int decide;
  cout<<"Type '1' if you want to register \n Type '2' if you want to login \n";
  cin>>decide;

  if (decide == 1){
    string userID, password;

    cout<<"Select a user ID:"; cin>>userID;
    cout<<"Select a password:"; cin>>password;

    ofstream file;
    file.open("data\\" + userID + ".txt");
    file << userID << endl << password;
    file.close();

    main();
  }else if (decide == 2){
    bool status = LoggedIn();

    if (!status){
      cout<< "Sorry, the login was not successful."<<endl;
      system("PAUSE");
      return 0;
    }else{
      cout<<"Success!"<<endl;
      system("PAUSE");
      return 1;
    }
  }
}
