#ifndef DRIVER_INCLUDED
#define DRIVER_INCLUDED
#include<iostream.h>
#include<stdio.h>
#include "Locations.h"
class driver{
  char dr_name[30];
  char dr_phoneno[15];
  char car_no[10];
  unsigned long int dr_no;
  double rating;
  Loc location;
public: 
  void input_data()
  {
    gets(dr_name);
    gets(car_no);
    cin>>dr_no;
    getLoc(location);
  }
  Loc get_location()
  {
    return location;
  }
  char* getUser()
  {
    return dr_name;
  }
};

#endif
