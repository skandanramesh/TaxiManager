#ifndef CUSTOMER_INCLUDED
#define CUSTOMER_INCLUDED
#include<fstream>
#include<stdio.h>
#include<string.h>
#include "locations.h"
#include "dates.h"
using namespace std;
class Customer
{
 int valid;
 char cuser[30];
 char cpass[30];
 char cname[30];
 char cpno[15];
 int lastRideRated;
 int noRides;
 Location defLoc;
 Date D;
 //char c[50];
 public:
 Customer(){valid=-1;noRides=0;}
 Customer(int a){valid=-1;noRides=0;}
 int isValid(){return valid;}
 int isLastRideRated (){return (noRides)?lastRideRated:1;}
 void rated(){lastRideRated=1;}
 char* getUser()
 {
  return cuser;
 }
 Customer incRide (){ noRides++;}
 char* getPass()
 {
  return cpass;
 }
 void setInfo()
 {
     cin.ignore(1000, '\n');
  cout<<"Enter your user name"<<endl;
  cin.getline(cuser, 30);
  cout<<"Enter your name"<<endl;
  cin.getline(cname, 30);
  while(1)
  {
    cout<<"Enter a strong password(8 to 30 characters)"<<endl;
    cin.getline(cpass, 30);
  }
  cout<<"Enter your date of birth"<<endl;;
  D.acceptdate();
  //cout<<"Enter your address";
  defLoc.setLoc();
  valid =1;
 }
 void printall(){cout<<"Printing "<<cuser<<" "<<cname<<endl;}
  void setUser(char* user)
 {
  strcpy(cuser, user);
 }
  Location getLocation(){return defLoc;}

};
void updateCustomer(Customer c)
{
  fstream f("Customer.dat", ios::binary|ios::in|ios::out|ios::ate);
  f.seekg(0, ios::beg);
  Customer c2;
  while(f.read((char*)&c2, sizeof(c2)))
  {
      if(c2.getUser ()==c.getUser ()){
        f.seekg(int(-1*sizeof(c)), ios::cur);
        f.write((char*)&c, sizeof(c));
      }
  }
  f.close();
}
#endif
