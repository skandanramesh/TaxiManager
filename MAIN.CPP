/**
   -INSTRUCTIONS-
 ------------------
* All choice variables used are int. (Don't check as ch=='1'. Use ch == 1  instead)
*/


//Header files
#include<fstream.h>
#include "customer.h"
#include<process.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
//#include "manager.h"
#include "etime.h"
#include "admin.h"
//#include "err_codes.h"
#include "rides.h"
#include "reg.cpp"
#include "login.cpp"
#include "Ride.cpp"
#include "support.cpp"
// global variables
    int ch;
   char user[30] = "";
    int loginStatus, regStatus;
// Program
void clearall(){remove("Customer.dat");}
void customerRegister(Customer c= Customer(), int rep =0)
{
	char* usr;
	if(rep>5){cout<<"Too many attempts"<<endl;return;}
	if(rep == 0)c.setInfo();
	else
	{
	    char str[5];int l= rand()%5+1;
	   for(int k=0;k<l;k++)
	      str[k]=char(rand()%10+48);
	    cout<<"Please re-enter another username(Try "<<strcat(c.getUser(), str)<<" instead. Or to cancel type CANCEL"<<endl;
	    gets(usr);
	    if(strcmp(usr, "CANCEL")==0)
	    {
		  regStatus = -1;
		   return;
	    }
	    c.setUser(usr);
	}
	int regStatus2 = reg(c);
	if(regStatus2==-1)
	{
	    cout<<"Username already exists."<<endl;
	    customerRegister(c, rep+1);
	}
	else{
	    cout<<"Registration Successful. Now Please login to continue"<<endl;
	    regStatus=1;
	    cin.get();
	    }
}
void letsTaxi(Session s)
{
    Customer c= s.retCustomer();
    while(1)
    {   cout<<"1.Book ride 2.Rate a previous ride 3.View previous rides. 4.logout 5.exit"<<endl;
	int ch;
	cin>>ch;
	if(ch==1)
	{
	    if(!c.isLastRideRated())
	    {
	       cout<<"Please rate last ride to book a new ride. Press c to cancel , any other button to rate and book"<<endl;
	       char cho;
	       cho = getch();
	       if(cho=='c'||cho=='C')continue;
	       rate_ride(c);
	    }
	     taxi_booking(c);
       }
       if(ch==2)
       {
	   if(c.isLastRideRated())
	   {  cout<<"All rides already rated"<<endl;
	      continue;
	   }
	    rate_ride(c);
       }
	else if(ch==3)support(c);
	else if(ch==4) {logout(s);return;}
	else if(ch==4+1)exit(0);
    }
}
void adminGoGoGo()
{
    while(1)
    {


      cout<<"1.Add Drivers. 2.Show Drivers 3.See Customer details.4.Read register log. 5. Read Session logs 6.Reset Records. 7.Logout"<<endl;
      int cho;
      cin>>cho;
      if(cho==1)addDrivers();
      else if(cho==2)showDrivers();
      else if(cho==3)customDetails();
      else if(cho==4)readLog();
      else if(cho==5)readSlog();
      else if(cho==6){
	cout<<"You are about to permanently delete all records. Enter admin password to continue or any other word to cancel"<<endl;
	char str[50];
	cin.getline(str, 50);
	if(strcmp(str, "RsSp##")==0)
	{
		remove("Customer.dat");
		remove("Driver.dat");
		remove("Rides.dat");
		cout<<"Deleting...."<<endl;
		cout<<"Successfully deleted"<<endl;
	}
      }
      else return;
}}
void intro()
{
    cout<<"-----------------------------------------------------------------------------"<<endl;
    cout<<"------------------------Welcome to Taxi Management System--------------------"<<endl;
    cout<<"-----------------------------------------------------------------------------"<<endl;
cout<<"                                @\n"
"               (__)    (__) _____/\n"
"            /| (oo) _  (oo)/----/_____    *\n"
"  _o\______/_|\_\/_/_|__\/|____|//////== *- *  * -\n"
" /_________   \   00 |   00 |       /== -* * -\n"
"[_____/^^\_____\_____|_____/^^\_____]     *- * -\n"
"      \__/                 \__/"<<endl;
   cout<<"What do you wish to do"<<endl;
}
int main()
{
   Customer c;
  // init_locs();
  srand((unsigned)time(0));
   Session s;
    while(1)
    {
	system("CLS");
	intro();
	cout<<"1.Login\t 2.Register\t 3.Exit"<<endl;
	cin>>ch;
	if(ch==3)return 0;
	if(ch==2)
	{
	    customerRegister();
	    //Customer cu;
	 //   reg(cu);f
	    continue;
	}
	if(ch==1)
	{
	    cout<<"Please enter username "<<endl;
	    cin.ignore();
	    cin.getline(user,30);
	    s=login(user);
	    Customer c = s.retCustomer();
	    if(c.isValid()==-1)
	       continue;
	    cout<<"Successfully logged in as "<<user<<endl;
	    letsTaxi(s);
	    continue;
	}
	if(ch==42)
	{
	    cin.ignore();
	    char us[30];
	    cin.getline(us, 30);
	    char pas[30];
	    cin.getline(pas, 30);
	    if(!(strcmp(us, "admin")==0&&strcmp(pas, "RsSp##")==0))
	    {

		exit(0);
	    }
	    cout<<"Successfully logged in as admin "<<endl;
	    adminGoGoGo();
	    cin.get();
	}
	else return 0;
    }
    return 0;
}
