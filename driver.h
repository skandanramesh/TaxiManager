#ifndef DRIVER_INCLUDED
#define DRIVER_INCLUDED
#include<iostream.h>
#include<stdio.h>
#include "Locations.h"
#define MAX_DISTANCE 200
class Driver{
  char dr_name[30];
  char dr_phoneno[15];
  char car_no[10];
  unsigned long int dr_no;
  double rating;
  Loc location;
  int noRides;
public:
  Driver(){location.x=200;location.y=200;noRides=0;}
  Driver(double d){rating=d;}
  void input_data()
  {
    gets(dr_name);
    gets(car_no);
    cin>>dr_no;
    getLoc(location);
  }
  Location get_location()
  {
    return location;
  }
  void printDetails()
  {
      cout<<"Name : "<<dr_name<<endl<<"Phone no: "<<dr_phoneno<<endl<<"Vehicle no. : "<<car_no<<endl;
  }
  void incRide(){noRides++;}
  void rate(double r){rating =  ( (noRides-1)*rating + r ) / noRides;}
  char* getUser()
  {
    return dr_name;
  }
  int isNull(){return (rating == -1)?1:0;}

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
    if(dist(temp.get_location(), pickup)<dist(select.get_location(), pickup))
     select=temp;
  }
  fin.close();
  if(dist(pickup, select.get_location())>MAX_DISTANCE)
    return nullDriver; // No near drivers
  return select;
}
void updateDriver(Driver d)
{
  fstream f("Driver.dat", ios::binary|ios::in|ios::out|ios::ate);
  f.seekg(0, ios::beg);
  Driver d2;
  while(f.read((char*)&d2, sizeof(d2)))
  {
      if(d2==d){
        f.seekg(int(-1*sizeof(d)), ios::cur);
        f.write((char*)&d, sizeof(d));
      }
  }
  f.close();
}
#endif
