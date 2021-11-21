#include <iostream>
#include <cstring>
#include<stdlib.h>
#include<iomanip>
#include<string.h>
#include <fstream>
#include "manageslot.h"
using namespace  std;


int main() {
  
  //variables
  int choice_1,choice_2;
  NodePtr head_m = NULL;
  NodePtr head_t = NULL;
  NodePtr head_w = NULL;
  NodePtr head_th = NULL;
  NodePtr head_f = NULL;
  NodePtr head_s = NULL;
  string line,pass,name,email,phone,input_password;
  
  do{
    
  do{
  cout<<"====================="<<endl;
  cout<<"Choose your option"<<endl;
  cout<<"1.Student"<<endl;
  cout<<"2.Professor"<<endl;
  cout<<"3.Exit"<<endl;
  cout<<"Your option: ";
    cin>>choice_1;
  }while(choice_1!=1&&choice_1!=2&&choice_1!=3);
  //cout<<"Please try again"<<endl;
  
  ifstream password("password.txt");
  
  switch(choice_1){
    case 1:
        cout<<"You are a student"<<endl;
        choice_2 = instruction_student();
        switchcase_student(choice_2,head_m,head_t,head_w,head_th,head_f,head_s);
        //cout<<choice_2<<endl;
        
        cout<<endl;
        break;
    
    case 2:
        cout<<"Enter password: ";
        cin>>input_password;
        //ifstream password("password.txt");
        while(!password.eof()){
          password>>pass;
          if(pass == input_password){
              password>>name;
              password>>email;
              password>>phone;
          }
          else continue;
          }
        if(pass=="\n"){
          cout<<"Password Incorrect"<<endl;
          break;
        }
        else{ 
          cout<<"You are a professor"<<endl;
          password.close();
          choice_2 = instruction_professor();
          switchcase_professor(choice_2,head_m,head_t,head_w,head_th,head_f,head_s, name, email, phone);
        //cout<<choice_2<<endl;
          cout<<endl;
          break;
        }
        
    default: break;
  }

  }while(choice_1!=3);


  return 0;
}

//https://replit.com/join/bntdqvqmgw-satidaruengsura