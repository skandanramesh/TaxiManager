/**
   -INSTRUCTIONS-
 ------------------
* All choice variables used are int. (Don't check as ch=='1'. Use ch == 1  instead)
*/


//Header files
#include<fstream.h>
#include "customer.h"
#include "manager.h"
#include "customtime.h"
#include "err_codes.h"

// global variables
    int ch;
    char* user = "";
    int loginStatus, regStatus;
    Customer dummyC;
// Program
void customerRegister(Customer c = dummy, int rep =0)
{
        char* usr;
        char* usr;
        if(rep == 0)c.getInfo();
        else
        {
            cout<<"Please re-enter another username or to cancel type CANCEL"<<endl;gets(usr);
            if(strcmp(usr, "CANCEL")==0)
            {
                  regStatus = -1;
                   return;
            }
            c.getUser(usr);
        }
        int regStatus2 = reg(c);
        if(regStatus2==-1)
        {
            cout<<"Username already exists."<<endl;
            register(c);
        }
        else{
            cout<<"Registration Successful. Now Please login to continue"<<endl;
            regStatus=1;
            }
}
void letsTaxi()
{
    while(1)
    {
        cout<<"1.Book ride 2..... n.Logout n+1.exit"<<endl;
        int ch;
        cin>>ch;
        if(ch==n) return;
        if(ch==n+1)exit(0);
    }
}

void main()
{

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
            if(!(loginStatus = login(user)))                   // I meant = only. [SOMEONE DONT CHANGE IT TO ==]
                 continue;                                    // See login.cpp for better understanding
            cout<<"Successfully logged in as "<<user<<endl;
            letsTaxi();
        }

    }

}
