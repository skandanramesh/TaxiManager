#ifndef CUSTOMER_INCLUDED
#define CUSTOMER_INCLUDED
class Customer
{
 char cust_user_name[30];
 char cust_pass[30];
 char cust_name[30];
 char cust_phone_no[15];
 strct Dob
 {
  int year;
  int month;
  int date;
  void displaydob()
  {
   cout<<date<<"-"<<month<<"-"<<year<<'\n';
  }
 };
 char cust_address[50];
};
#endif
