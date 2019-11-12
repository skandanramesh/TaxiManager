#ifndef CUSTOMER_INCLUDED
#define CUSTOMER_INCLUDED
#include<iostream.h>
#include<stdio.h>
#include<string.h>
#include "locations.h"
 
class Customer
{
 int valid;
 char cust_user_name[30];
 char cust_pass[30];
 char cust_name[30];
 char cust_phone_no[15];
 int lastRideRated;
 int noRides;
 Location defLoc;
 struct Dob
 {
  int year;
  int month;
  int date;
  void acceptdob()
  {
   cout<<"Enter date";
   cin>>date;
   cout<<"Enter month number";
   cin>>month;
   cout<<"Enter year";
   cin>>year;
  }
  void displaydob()
  {
   cout<<date<<"-"<<month<<"-"<<year<<'\n';
  }
 }D;
 char cust_address[50];
 public:
 Customer(){valid=-1;}
 Customer(int a){valid=-1;}
 int isValid(){return valid;}
 int isLastRideRated (){return lastRideRated;}
 char* getUser()
 {
  return cust_user_name;
 }
 Customer incRide (){ noRides++; lastRideRated=0;}
 char* getPass()
 {
  return cust_pass;
 }
 void setInfo()
 {
  cout<<"Enter your user name";
  gets(cust_user_name);
  cout<<"Enter a strong password";
  gets(cust_pass);
  cout<<"Enter your date of birth";
  D.acceptdob();
  cout<<"Enter your address";
  Loc defLoc;
  getLoc(defLoc);
 }
  void setUser(char* user)
 {
  strcpy(cust_user_name,user);
 }
  Location getLocation(){return defLoc;}
 valid=1;noRides=0;lastRideRated=1;
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
