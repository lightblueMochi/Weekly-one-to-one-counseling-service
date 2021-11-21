#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <iomanip>
#include <string.h>
#include "node.h"

using namespace  std;

int instruction_student();
void switchcase_student(int, NodePtr &, NodePtr &, NodePtr &, NodePtr &, NodePtr &, NodePtr &);
void switchcase_professor(int, NodePtr &, NodePtr &, NodePtr &, NodePtr &, NodePtr &, NodePtr &);
void create_node(NodePtr &,string, string, string, string, string, int, int, int, int, int);
void create_time(NodePtr &, NodePtr &, NodePtr &, NodePtr &, NodePtr &, NodePtr &);
int delete_node(NodePtr &, int);
int delete_time(NodePtr &, NodePtr &, NodePtr &, NodePtr &, NodePtr &, NodePtr &);
void display(NodePtr, NodePtr, NodePtr, NodePtr, NodePtr, NodePtr);
int findncancel(NodePtr, int, int);
int book_time(NodePtr, NodePtr, NodePtr, NodePtr, NodePtr, NodePtr);
int findncancel(NodePtr, int, int);
int cancel_booking(NodePtr, NodePtr, NodePtr, NodePtr, NodePtr, NodePtr);


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

void create_node(NodePtr &head,string input_name, string input_email, string input_phone, string input_day, string input_room, int input_sectionID, int input_starthr, int input_startmin, int input_endhr, int input_endmin){
  NodePtr newPtr = new section;
  NodePtr currentPtr = head;
  NodePtr previousPtr = NULL;
  

  if(newPtr){
    newPtr->p.name = input_name;
    newPtr->p.email = input_email;
    newPtr->p.phone = input_phone;

    newPtr->section_id = input_sectionID;
    newPtr->day = input_day;
    newPtr->start_hr = input_starthr;
    newPtr->start_min = input_startmin;
    newPtr->finish_hr = input_endhr;
    newPtr->finish_min = input_endmin;
    newPtr->roomNumber = input_room;
    newPtr->status = "available";
    
    while(currentPtr!=NULL && input_endhr>=currentPtr->start_hr){
      if(input_endhr==currentPtr->start_hr&&input_endmin<=currentPtr->start_min) break;
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
    cout<<"Successfully added the section."<<endl;
  }
}

void create_time(NodePtr &head_m, NodePtr &head_t, NodePtr &head_w, NodePtr &head_th, NodePtr &head_f, NodePtr &head_s){
  string input_name, input_email, input_phone, input_room, input_day;
  int input_sectionID, input_starthr, input_startmin, input_endhr, input_endmin, i;
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
    cout<<"Day of the week(mon-sat): ";
    cin>>input_day;
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

    /*for(i=0;i<strlen(input_day);i++){
      input_day[i]=tolower(input_day[i]);
    }
    */
    
    if(input_day == "monday"){
      create_node(head_m, input_name, input_email, input_phone, input_day, input_room, input_sectionID, input_starthr, input_startmin, input_endhr, input_endmin); 
    }
    else if(input_day == "tuesday"){
      create_node(head_t, input_name, input_email, input_phone, input_day, input_room, input_sectionID, input_starthr, input_startmin, input_endhr, input_endmin); 
      }
    else if(input_day == "wednesday"){
      create_node(head_w, input_name, input_email, input_phone, input_day, input_room, input_sectionID, input_starthr, input_startmin,input_endhr, input_endmin); 
      }
    else if(input_day == "thursday"){
      create_node(head_th, input_name, input_email, input_phone, input_day, input_room, input_sectionID, input_starthr, input_startmin, input_endhr, input_endmin); 
      }
    else if(input_day == "friday"){
      create_node(head_f,input_name, input_email, input_phone, input_day, input_room, input_sectionID, input_starthr, input_startmin, input_endhr, input_endmin); 
      }
    else if(input_day == "saturday"){
      create_node(head_s, input_name, input_email, input_phone, input_day, input_room, input_sectionID, input_starthr, input_startmin, input_endhr, input_endmin); 
    }
  
    do{
      cout<<"Do you want to add more section?(y/n): ";
      cin>>yn;
    }while(yn!='y'&&yn!='n');
  }while(yn=='y');
}

int delete_node(NodePtr &head, int input_sectionID){
  NodePtr currentPtr;
  NodePtr previousPtr;
  NodePtr tempPtr;

  if(input_sectionID==head->section_id){
    tempPtr = head;
    head = head->next;
    if(head) head->previous = NULL;
    delete tempPtr;
    return 1;
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
      return 1;
    }
  }
}

int delete_time(NodePtr &head_m, NodePtr &head_t, NodePtr &head_w, NodePtr &head_th, NodePtr &head_f, NodePtr &head_s){
  //display();
  int input_sectionID;
  /*NodePtr currentPtr;
  NodePtr previousPtr;
  NodePtr tempPtr;
  */

  cout<<"What is the section ID that you want to delete?"<<endl;
  cin>>input_sectionID;
  
 
  if(delete_node(head_m,input_sectionID)>0) return input_sectionID;
  else if(delete_node(head_t,input_sectionID)>0) return input_sectionID;
  else if(delete_node(head_w,input_sectionID)>0) return input_sectionID;
  else if(delete_node(head_th,input_sectionID)>0) return input_sectionID;
  else if(delete_node(head_f,input_sectionID)>0) return input_sectionID;
  else if(delete_node(head_s,input_sectionID)>0) return input_sectionID;
  else return 0;
  
  
}

void display(NodePtr head_m, NodePtr head_t, NodePtr head_w, NodePtr head_th, NodePtr head_f, NodePtr head_s){
  NodePtr currentPtr = head_m;
  if(currentPtr==NULL){
    cout<<"Time slot is empty"<<endl;
  }
  else{
    cout<<"===Time slot==="<<endl;
    cout<<"-Monday-"<<endl;
    while(currentPtr!=NULL){
    cout<<setfill('0')<<setw(2)<<currentPtr->start_hr<<":"<<setfill('0')<<setw(2)<<currentPtr->start_min<<" - "<<setfill('0')<<setw(2)<<currentPtr->finish_hr<<":"<<setfill('0')<<setw(2)<<currentPtr->finish_min<<endl;
    cout<<"Section ID: "<<currentPtr->section_id<<endl;
    cout<<"Professor "<<currentPtr->p.name<<endl;
    cout<<"Status: "<<currentPtr->status<<endl;
    cout<<"-------------"<<endl;
    currentPtr = currentPtr->next;
    }
    
    currentPtr = head_t;
    cout<<"-Tuesday-"<<endl;
    while(currentPtr!=NULL){
    cout<<setfill('0')<<setw(2)<<currentPtr->start_hr<<":"<<setfill('0')<<setw(2)<<currentPtr->start_min<<" - "<<setfill('0')<<setw(2)<<currentPtr->finish_hr<<":"<<setfill('0')<<setw(2)<<currentPtr->finish_min<<endl;
    cout<<"Section ID: "<<currentPtr->section_id<<endl;
    cout<<"Professor "<<currentPtr->p.name<<endl;
    cout<<"Status: "<<currentPtr->status<<endl;
    cout<<"-------------"<<endl;
    currentPtr = currentPtr->next;
    }

    currentPtr = head_w;
    cout<<"-Wednesday-"<<endl;
    while(currentPtr!=NULL){
    cout<<setfill('0')<<setw(2)<<currentPtr->start_hr<<":"<<setfill('0')<<setw(2)<<currentPtr->start_min<<" - "<<setfill('0')<<setw(2)<<currentPtr->finish_hr<<":"<<setfill('0')<<setw(2)<<currentPtr->finish_min<<endl;
    cout<<"Section ID: "<<currentPtr->section_id<<endl;
    cout<<"Professor "<<currentPtr->p.name<<endl;
    cout<<"Status: "<<currentPtr->status<<endl;
    cout<<"-------------"<<endl;
    currentPtr = currentPtr->next;
    }

    currentPtr = head_th;
    cout<<"-Thursday-"<<endl;
    while(currentPtr!=NULL){
    cout<<setfill('0')<<setw(2)<<currentPtr->start_hr<<":"<<setfill('0')<<setw(2)<<currentPtr->start_min<<" - "<<setfill('0')<<setw(2)<<currentPtr->finish_hr<<":"<<setfill('0')<<setw(2)<<currentPtr->finish_min<<endl;
    cout<<"Section ID: "<<currentPtr->section_id<<endl;
    cout<<"Professor "<<currentPtr->p.name<<endl;
    cout<<"Status: "<<currentPtr->status<<endl;
    cout<<"-------------"<<endl;
    currentPtr = currentPtr->next;
    }

    currentPtr = head_f;
    cout<<"-Friday-"<<endl;
    while(currentPtr!=NULL){
    cout<<setfill('0')<<setw(2)<<currentPtr->start_hr<<":"<<setfill('0')<<setw(2)<<currentPtr->start_min<<" - "<<setfill('0')<<setw(2)<<currentPtr->finish_hr<<":"<<setfill('0')<<setw(2)<<currentPtr->finish_min<<endl;
    cout<<"Section ID: "<<currentPtr->section_id<<endl;
    cout<<"Professor "<<currentPtr->p.name<<endl;
    cout<<"Status: "<<currentPtr->status<<endl;
    cout<<"-------------"<<endl;
    currentPtr = currentPtr->next;
    }
      
    currentPtr = head_s;
    cout<<"-Saturday-"<<endl;
    while(currentPtr!=NULL){
    cout<<setfill('0')<<setw(2)<<currentPtr->start_hr<<":"<<setfill('0')<<setw(2)<<currentPtr->start_min<<" - "<<setfill('0')<<setw(2)<<currentPtr->finish_hr<<":"<<setfill('0')<<setw(2)<<currentPtr->finish_min<<endl;
    cout<<"Section ID: "<<currentPtr->section_id<<endl;
    cout<<"Professor "<<currentPtr->p.name<<endl;
    cout<<"Status: "<<currentPtr->status<<endl;
    cout<<"-------------"<<endl;
    currentPtr = currentPtr->next;
    }
  
  cout<<endl;
  }
}

void switchcase_professor(int choice, NodePtr &head_m, NodePtr &head_t, NodePtr &head_w, NodePtr &head_th, NodePtr &head_f, NodePtr &head_s){
  int deleted;
  switch(choice){
    case 1: create_time(head_m, head_t, head_w, head_th, head_f, head_s);
            break;
    case 2: deleted = delete_time(head_m, head_t, head_w, head_th, head_f, head_s);
            if(deleted>0) cout<<"Deleted section "<<deleted<<" successfully."<<endl;
            else cout<<"This section doesn't exist"<<endl;
            break;
    case 3: display(head_m, head_t, head_w, head_th, head_f, head_s);
            break;
    default: break;
  }
}

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

int findnbook(NodePtr head, int input_sectionID, string input_name, int input_studentID){
  NodePtr currentPtr = head;
  while(currentPtr->next!=NULL){
    if(currentPtr->section_id!=input_sectionID){
      currentPtr = currentPtr->next;
    }
    else 
    break;
  };

  if(currentPtr->section_id==input_sectionID && currentPtr->status!="Not available"){
    currentPtr->s.id = input_studentID;
    currentPtr->s.name = input_name;
    currentPtr->status = "Not available";
    cout<<"You successfully booked Section ID:"<<currentPtr->section_id<<endl;
    cout<<"Day: "<<currentPtr->day<<endl;
    cout<<"Time: "<<setfill('0')<<setw(2)<<currentPtr->start_hr<<":"<<setfill('0')<<setw(2)<<currentPtr->start_min<<"-"<<setfill('0')<<setw(2)<<currentPtr->finish_hr<<":"<<setfill('0')<<setw(2)<<currentPtr->finish_min<<endl;
    cout<<"Professor "<<currentPtr->p.name<<endl;
    cout<<"Email: "<<currentPtr->p.email<<endl;
    cout<<"Phone: "<<currentPtr->p.phone<<endl;
    //cout<<currentPtr->s.id<<endl;
    return 1;
  }
  //else cout<<"This section is not available. Please try again."<<endl;
  else return 0;
}

int book_time(NodePtr head_m, NodePtr head_t, NodePtr head_w, NodePtr head_th, NodePtr head_f, NodePtr head_s){
  string input_name;
  int input_sectionID, input_studentID;
  //NodePtr currentPtr = head;

  cout<<endl;
  cout<<"Name: ";
  cin>>input_name;
  //cout<<" "<<endl;
  cout<<"Student ID: ";
  cin>>input_studentID;
  //cout<<input_studentID<<endl;

  cout<<" "<<endl;
  display(head_m,head_t,head_w,head_th,head_f,head_s);
  
  cout<<"Enter section ID that you want to reserve: ";
  cin>>input_sectionID;
  
  if(findnbook(head_m,input_sectionID,input_name,input_studentID)>0) return 1;
  else if(findnbook(head_t,input_sectionID,input_name,input_studentID)>0) return 1;
  else if(findnbook(head_w,input_sectionID,input_name,input_studentID)>0) return 1;
  else if(findnbook(head_th,input_sectionID,input_name,input_studentID)>0) return 1;
  else if(findnbook(head_f,input_sectionID,input_name,input_studentID)>0) return 1;
  else if(findnbook(head_s,input_sectionID,input_name,input_studentID)>0) return 1;
  else return 0;
  
}

int findncancel(NodePtr head, int input_sectionID, int input_studentID){

  NodePtr currentPtr = head;

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
    
      if(currentPtr->s.id==input_studentID){
        currentPtr->s.name = " ";
        currentPtr->s.id = 0;
        currentPtr->status = "available";
        cout<<"Cancel the booking successfully."<<endl;
        return 1;
      }
      else cout<<"Your student ID doesn't match."<<endl;
      return 0;
    }
  }
}

int cancel_booking(NodePtr head_m, NodePtr head_t, NodePtr head_w, NodePtr head_th, NodePtr head_f, NodePtr head_s){
  int input_studentID,input_sectionID;
  //NodePtr currentPtr = head;
  
  cout<<"Section ID: ";
  cin>>input_sectionID;
  
  if(findncancel(head_m,input_sectionID,input_studentID)>0) return input_sectionID;
  else if(findncancel(head_t,input_sectionID,input_studentID)>0) return 1;
  else if(findncancel(head_w,input_sectionID,input_studentID)>0) return 1;
  else if(findncancel(head_th,input_sectionID,input_studentID)>0) return 1;
  else if(findncancel(head_f,input_sectionID,input_studentID)>0) return 1;
  else if(findncancel(head_s,input_sectionID,input_studentID)>0) return 1;
  else return 0;
  
}

void switchcase_student(int choice, NodePtr &head_m, NodePtr &head_t, NodePtr &head_w, NodePtr &head_th, NodePtr &head_f, NodePtr &head_s){
  int booked;
  switch(choice){

    case 1: booked = book_time(head_m,head_t,head_w,head_th,head_f,head_s);
            if(booked==0) cout<<"This section is not available. Please try again."<<endl;
            break;
    case 2: cancel_booking(head_m,head_t,head_w,head_th,head_f,head_s);
            if(booked==0) cout<<"This section is not available. Please try again."<<endl;
            break;
    case 3: display(head_m,head_t,head_w,head_th,head_f,head_s);
            break;
    default: break;
    
  }
}
