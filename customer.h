#ifndef CUSTOMER_INCLUDED
#define CUSTOMER_INCLUDED
#include<iostream>
#include<stdio.h>
#include<string.h>
#include "locations.h"
 using namespace std;

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
 Customer(){valid=1;noRides=0;lastRideRated=1;}
 Customer(int a){valid=-1;}
 int isValid(){return valid;}
 int isLastRideRated (){return lastRideRated;}
 char* getUser()
 {
  return cust_user_name;
 }
 void incRide (){ noRides++; lastRideRated=0;}
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
  gets(cust_address);
  getLoc(defLoc);
 }
  void setUser(char* user)
 {
  strcpy(cust_user_name,user);
 }
  Location getLocation(){return defLoc;}
};
#endif
