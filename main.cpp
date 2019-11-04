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
#include "customtime.h"
//#include "err_codes.h"
#include "rides.h"
#include "reg.cpp"
#include "login.cpp"
#include "Ride.cpp"
// global variables
    int ch;
   // char* user = "";
    int loginStatus, regStatus;
    Customer dummy;
// Program
void customerRegister(Customer c = dummy, int rep =0)
{
        char* usr;
        if(rep == 0)c.setInfo();
        else
        {
            char str[5];int l= random(5)+1;
           for(int k=0;k<l;k++)
              str[k]=char(random(10)+48);
            cout<<"Please re-enter another username(Try "<<strcat(c.getUser(), str)<<" instead. Or to cancel type CANCEL"<<endl;gets(usr);
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
            }
}
void letsTaxi(Customer c)
{
    while(1)
    { using namespace std;

        cout<<"1.Book ride 2.Rate a previous ride 3.logout 4.exit"<<endl;
        int ch;
        cin>>ch;
       if(ch==1)
       {
            if(!c.isLastRideRated())
            {cout<<"Please rate last ride to book a new ride "<<endl;
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
        else if(ch==3) return;
        else if(ch==3+1)exit(0);
    }
}
void adminGoGoGo()
{
      //Todo
}

void main()
{
   Customer c;
   init_locs();
   randomize();
    while(1)
    {
        cout<<"Welcome to Taxi Management System "<<endl;
        cout<<"1.Login\t 2.Register\t 3.Exit"<<endl;
        cin>>ch;
        if(ch==2)
        {
            customerRegister();
            continue;
        }
        if(ch==1)
        {
            cout<<"Please enter username "<<endl;
            gets(user);
            c=login(user);
            if(!c.isValid())
               continue;
            cout<<"Successfully logged in as "<<user<<endl;
            letsTaxi(c);
        }
        if(ch==22)
        {
            gets(user);
            char* pass;
            gets(pass);
            if(!(user=="admim"&&pass=="RsSp##"))
            {
                cout<<"FATAL ERROR OCCURED DUE TO ATTEMPT OF SECURITY BREACH. Press any key to continue"<<endl;
                getch();
                exit(0);
            }
            cout<<"Successfully logged in as admin "<<endl;
            adminGoGoGo();

        }
    }

}
