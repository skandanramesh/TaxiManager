#ifndef DRIVER_INCLUDED
#define DRIVER_INCLUDED
#include<iostream.h>
#include<stdio.h>
#include "loc.h"
#include "vehicles.h"
#define MAX_DISTANCE 200
class Driver{
  char dr_user[30];
  char dr_name[30];
  char dr_phoneno[15];
  //char car_no[10];
  unsigned long int dr_no;
  double rating;
  Loc dloc;
  int noRides;
  Vehicle *vptr;
public:
  Driver(){dloc.x=200;dloc.y=200;noRides=0;}
  Driver(double d){rating=d;}
  char* getName(){return dr_name;}
  void getveh(){vptr->printVehName();}
  int getvehType(){return vptr->getVehType();}
  void input_data()
  {
    cin.ignore(1000, '\n');
    cout<<"Enter driver name"<<endl;
    cin.getline(dr_name, 30);
    cout<<"Enter unique driver id"<<endl;
    cin>>dr_no;
    dloc.setLoc();
    cout<<"1.Car 2.Bike"<<endl;
    char ch;
    cin>>ch;
    if(ch==1)
   {Car c; vptr = &c;}
    else {Bike b;vptr= &b;}
    vptr->getDetails();
  }
  Location get_location()
  {
    return dloc;
  }
  void printDetails()
  {
      cout<<"Name : "<<dr_name<<endl<<"Phone no: "<<dr_phoneno<<endl;
      vptr->printVehName();
  }
  void superDetails()
  {
      cout<<"Name : "<<dr_name<<endl<<"Phone no: "<<dr_phoneno<<endl;
      vptr->printVehName();
      cout<<"Driver number: "<<dr_no<<endl<<endl;
  }
  unsigned long int getNo(){return dr_no;}
  Driver* incRide(){noRides++;return this;}
  void rate(double r){rating =  ( (noRides-1)*rating + r ) / noRides;}
  char* getUser()
  {
    return dr_name;
  }
  int isNull(){return (rating == -1)?1:0;}

};
const Driver nullDriver(-1);

Driver nearestDriver(Location pickup, int choi)
{
  ifstream fin("Driver.dat", ios::binary);
  Driver temp, select;
  int f=0;
  if(!fin)return nullDriver;
  fin.read((char*)&temp, sizeof(Driver));
  select=temp;
  while(fin.read((char*)&temp, sizeof(Driver)))
  {
    if(dist(temp.get_location(), pickup)<dist(select.get_location(), pickup)&&temp.getvehType()==choi)
     select=temp;
  }
  fin.close();
  if(dist(pickup, select.get_location())>MAX_DISTANCE)
    return nullDriver; // No near drivers
  return select;
}
void updateDriver(Driver *d)
{
  fstream f("Driver.dat", ios::binary|ios::in|ios::out|ios::ate);
  f.seekg(0, ios::beg);
  Driver d2;
  while(f.read((char*)&d2, sizeof(d2))){
      if(d2.getUser ()==d->getUser()) {
        f.seekg(int(-1*sizeof(d2)), ios::cur);
        f.write((char*)d, sizeof(d2));
      }
  }
  f.close();
}
void writeDriver(Driver d)
{
  ofstream f("Driver.dat",ios::binary);
  f.write((char*)&d, sizeof(d));
  f.close();
  cout<<"Driver written into records"<<endl;
  cout<<"Press any key to continue"<<endl;
  getch();
}
#endif
