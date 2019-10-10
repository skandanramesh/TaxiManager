#ifndef DRIVER_INCLUDED
#define DRIVER_INCLUDED
#include<iostream.h>
#include<stdio.h>
#include "Locations.h"
#define MAX_DISTANCE 200;
class Driver{
  char dr_name[30];
  char dr_phoneno[15];
  char car_no[10];
  unsigned long int dr_no;
  double rating;
  Loc location;
public: 
  Driver(){location.x=200;location.y=200;}
  Driver(double d){rating=d;}
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
const Driver nullDriver(-1);
Driver nearestDriver(Location pickup)
{
  ifstream fin("Driver.dat", ios::binary);
  Driver temp, select;
  int f=0;
  if(!fin)return nullDriver;
  fin.read((char*)&temp, sizeof(Driver));
  select=temp;
  while(fin.read((char*)&temp, sizeof(Driver)))
  {
    if(distance(temp.get_location(), pickup)<distance(select.get_location(), pickup))
      select=temp;
  }
  fin.close();
  if(distance(pickup, select.get_location())>MAX_DISTANCE)
    return nullDriver; // No near drivers
  return select;
}
#endif
