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
  string day;
  string roomNumber;
  string status;

  struct section *next;
  struct section *previous;

};

typedef section* NodePtr;