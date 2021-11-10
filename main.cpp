#include <iostream>
#include<stdlib.h>
#include<iomanip>
using namespace  std;
#include "function.h"

int main() {
  
  //variables
  int choice_1,choice_2;
  NodePtr head = NULL;

  do{
    
  do{
  cout<<"Choose your option"<<endl;
  cout<<"1.Student"<<endl;
  cout<<"2.Professor"<<endl;
  cout<<"3.Exit"<<endl;
  cout<<"Your option: ";
    cin>>choice_1;
  }while(choice_1!=1&&choice_1!=2&&choice_1!=3);
  //cout<<"Please try again"<<endl;
  
  switch(choice_1){
    case 1:
        cout<<"You are a student"<<endl;
        choice_2 = instruction_student();
        switchcase_student(choice_2,head);
        //cout<<choice_2<<endl;
        
        cout<<endl;
        break;
    
    case 2:
        cout<<"You are a professor"<<endl;
        choice_2 = instruction_professor();
        switchcase_professor(choice_2,head);
        //cout<<choice_2<<endl;
        cout<<endl;
        break;
    default: break;
  }

  }while(choice_1!=3);


  return 0;
}