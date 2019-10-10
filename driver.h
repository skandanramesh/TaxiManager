#ifndef DRIVER_INCLUDED
#define DRIVER_INCLUDED
#include<iostream.h>
#include<stdio.h>
class driver{
  char* dr_name;
  char* dr_phoneno;
  char* car_no;
  unsigned long int dr_no;
  double rating;
  char* location;
public: 
  void input_data()
  {
    getline(dr_name);
    getline>>car_no;
    cin>> dr_no;
    getline(location);
  }
  char* get_location()
  {
    return location;
  }
  char* getUser()
  {
    return dr_name;
  }
};

#endif
