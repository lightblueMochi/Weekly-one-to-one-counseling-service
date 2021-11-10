#include <iostream>
#include<stdlib.h>
#include<iomanip>
using namespace  std;

struct student {

  int id;
  string name;

};

struct professor {

  string phone;
  string email;
  string name;

};

struct section {

  struct student s;
  struct professor p;
  int section_id;
  int start_hr;
  int start_min;
  int finish_hr;
  int finish_min;
  string roomNumber;
  string status;

  struct section *next;
  struct section *previous;

};

typedef section* NodePtr;

int instruction_student();
int instruction_professor();
void switchcase_student(int);
void switchcase_professor(int);


int instruction_student(){
  int choice_2;
  cout<<endl;
  do{
  cout<<"Choose your option:"<<endl;
  cout<<"1.Book the time"<<endl;
  cout<<"2.Cancel booking"<<endl;
  cout<<"3.Display the time slot"<<endl;
  cout<<"4.Exit"<<endl;
  cout<<"Your option: ";
  cin>>choice_2;
  }while(choice_2!=1&&choice_2!=2&&choice_2!=3&&choice_2!=4);
  return choice_2;
}

int instruction_professor(){
  int choice_2;
  cout<<endl;
  do{
  cout<<"Choose your option:"<<endl;
  cout<<"1.Create the time slot"<<endl;
  cout<<"2.Delete time slot"<<endl;
  cout<<"3.Display the time slot"<<endl;
  cout<<"4.Exit"<<endl;
  cout<<"Your option: ";
  cin>>choice_2;
  }while(choice_2!=1 && choice_2!=2 && choice_2!=3 &&choice_2!=4);
  return choice_2;
}

void create_time(NodePtr &head){
  string input_name, input_email, input_phone, input_room;
  int input_sectionID, input_starthr, input_startmin, input_endhr,
 input_endmin;
  char yn;

  cout<<"Name: ";
  cin>>input_name;
  cout<<"Email: ";
  cin>>input_email;
  cout<<"Phone: ";
  cin>>input_phone;

  do{
    cout<<"Section ID: ";
    cin>>input_sectionID;
    cout<<"Start at"<<endl;
    cout<<"Hour: ";
    cin>>input_starthr;
    cout<<"Minute: ";
    cin>>input_startmin;
    cout<<"End at"<<endl;
    cout<<"Hour: ";
    cin>>input_endhr;
    cout<<"Minute: ";
    cin>>input_endmin;
    cout<<"Room number: ";
    cin>>input_room;

  NodePtr newPtr = new section;
  NodePtr currentPtr = head;
  NodePtr previousPtr = NULL;
  
  if(newPtr){
    newPtr->p.name = input_name;
    newPtr->p.email = input_email;
    newPtr->p.phone = input_phone;

    newPtr->section_id = input_sectionID;
    newPtr->start_hr = input_starthr;
    newPtr->start_min = input_startmin;
    newPtr->finish_hr = input_endhr;
    newPtr->finish_min = input_endmin;
    newPtr->roomNumber = input_room;
    newPtr->status = "available";
    
    while(currentPtr!=NULL && input_endhr<=currentPtr->start_hr){
      if(input_endhr==currentPtr->start_hr&&input_endmin>currentPtr->start_min) break;
      else{
        previousPtr = currentPtr;                
         currentPtr = currentPtr->next;
      }
    }

    if(previousPtr==NULL){
      newPtr->next = head;
      if(head) head->previous = newPtr;
      head = newPtr;
    }
    else{
      previousPtr->next = newPtr;
      newPtr->previous = previousPtr;
      newPtr->next = currentPtr;
      if(currentPtr) currentPtr->previous = newPtr;
    }
  }
  
    do{
      cout<<"Do you want to add more section?(y/n): ";
      cin>>yn;
    }while(yn!='y'&&yn!='n');
  }while(yn=='y');
}

int delete_time(NodePtr &head){
  //display();
  int input_sectionID,value;
  NodePtr currentPtr;
  NodePtr previousPtr;
  NodePtr tempPtr;

  cout<<"What is the section ID that you want to delete?"<<endl;
  cin>>input_sectionID;

  if(input_sectionID==head->section_id){
    tempPtr = head;
    head = head->next;
    if(head) head->previous = NULL;
    delete tempPtr;
    return input_sectionID;
  }
  else{
    previousPtr = head;
    currentPtr = head->next;

    while(currentPtr!=NULL && currentPtr->section_id!=input_sectionID){
      previousPtr = currentPtr;
      currentPtr = currentPtr->next;
    }
    if(currentPtr){
      tempPtr = currentPtr;
      currentPtr = currentPtr->next;
      currentPtr->previous = previousPtr;
      previousPtr->next = currentPtr;
      delete tempPtr;
      return input_sectionID;
    }
  }
}

void display(NodePtr head){
  NodePtr currentPtr = head;
  if(currentPtr==NULL){
    cout<<"Time slot is empty"<<endl;
  }
  else{
    cout<<"===Time slot==="<<endl;
    while(currentPtr!=NULL){
    cout<<setfill('0')<<setw(2)<<currentPtr->start_hr<<":"<<setfill('0')<<setw(2)<<currentPtr->start_min<<" - "<<setfill('0')<<setw(2)<<currentPtr->finish_hr<<":"<<setfill('0')<<setw(2)<<currentPtr->finish_min<<endl;
    cout<<"Section ID: "<<currentPtr->section_id<<endl;
    cout<<"Professor "<<currentPtr->p.name<<endl;
    cout<<"Status: "<<currentPtr->status<<endl;
    cout<<"-------------"<<endl;
    currentPtr = currentPtr->next;
    }
  }
  cout<<endl;
}

void book_time(NodePtr head){
  string input_name;
  int input_starthr, input_startmin, input_sectionID, input_studentID;
  NodePtr currentPtr = head;

  cout<<endl;
  cout<<"Name: ";
  cin>>input_name;
  //cout<<" "<<endl;
  cout<<"Student ID: ";
  cin>>input_studentID;
  //cout<<input_studentID<<endl;

  cout<<" "<<endl;
  display(head);
  
  cout<<"Enter section ID that you want to reserve: ";
  cin>>input_sectionID;
  
  while(currentPtr->next!=NULL){
    if(currentPtr->section_id!=input_sectionID){
      currentPtr = currentPtr->next;
    }
    else break;
  }

  if(currentPtr->section_id==input_sectionID && currentPtr->status!="Not available"){
    currentPtr->s.id = input_studentID;
    currentPtr->s.name = input_name;
    currentPtr->status = "Not available";
    cout<<"You successfully booked Section ID:"<<currentPtr->section_id<<endl;
    cout<<"Time: "<<setfill('0')<<setw(2)<<currentPtr->start_hr<<":"<<setfill('0')<<setw(2)<<currentPtr->start_min<<"-"<<setfill('0')<<setw(2)<<currentPtr->finish_hr<<":"<<setfill('0')<<setw(2)<<currentPtr->finish_min<<endl;
    cout<<"Professor "<<currentPtr->p.name<<endl;
    cout<<"Email: "<<currentPtr->p.email<<endl;
    cout<<"Phone: "<<currentPtr->p.phone<<endl;
    //cout<<currentPtr->s.id<<endl;
  }
  else cout<<"This section is not available. Please try again."<<endl;
}

void cancel_booking(NodePtr head){
  int input_studentID,input_sectionID;
  NodePtr currentPtr = head;
  
  cout<<"Section ID: ";
  cin>>input_sectionID;
  
  if(currentPtr){
  while(currentPtr->next!=NULL){
    if(currentPtr->section_id!=input_sectionID){
      currentPtr = currentPtr->next;
    }
    else break;
  }
  if(currentPtr->section_id==input_sectionID){
    cout<<"Do you want to cancel section ID "<<currentPtr->section_id<<" at "<<setw(2)<<currentPtr->start_hr<<":"<<setw(2)<<currentPtr->start_min<<"-"<<setw(2)<<currentPtr->finish_hr<<":"<<setw(2)<<currentPtr->finish_min<<"?"<<endl;
    cout<<"If yes, please enter your student ID: ";
    cin>>input_studentID;
    //cout<<input_studentID<<endl;
    //cout<<currentPtr->s.name<<endl;
    //cout<<currentPtr->s.id<<endl;
    if(currentPtr->s.id==input_studentID){
      //cout<<"Checkpoint"<<endl;
      currentPtr->s.name = " ";
      currentPtr->s.id = 0;
      currentPtr->status = "available";
      cout<<"Cancel the booking successfully."<<endl;
    }
    else cout<<"Your student ID doesn't match."<<endl;
  }
  else cout<<"This student ID hasn't booked the time yet."<<endl;
}
else cout<<"There is no section."<<endl;
}

void switchcase_student(int choice, NodePtr &head){
  switch(choice){

    case 1: book_time(head);
            break;
    case 2: cancel_booking(head);
            break;
    case 3: display(head);
            break;
    default: break;
    
  }
}

void switchcase_professor(int choice, NodePtr &head){
  int deleted;
  switch(choice){
    case 1: create_time(head);
            break;
    case 2: deleted = delete_time(head);
            cout<<"Deleted section "<<deleted<<" successfully."<<endl;
            break;
    case 3: display(head);
            break;
    default: break;
  }
}