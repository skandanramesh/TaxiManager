#ifndef CUSTOMER_INCLUDED
#define CUSTOMER_INCLUDED
#include<iostream.h>
#include<stdio.h>
#include<string.h>

class Customer
{
 char cust_user_name[30];
 char cust_pass[30];
 char cust_name[30];
 char cust_phone_no[15];
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
 char* getUser()
 {
  return cust_user_name;
 }
 char* getPass()
 {
  return cust_pass;
 }
 void setInfo()
 {
  cout<<"Enter your user name";
  gets(cust_user_name);
  cout<<"Enter a strong password"
  gets(cust_pass);
  cout<<"Enter your date of birth";
  D.acceptdob();
  cout<<"Enter your address";
  gets(cust_address);
 }
  void setUser(char* user)
 {
  strcpy(cust_user_name,user);
 }

};
#endif
