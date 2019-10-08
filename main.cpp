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
    int prof = -1;
    int loginStatus, regStatus;
    Customer dummyC;
    Manager dummyM;
    Admin dummyA;
// Program
char* showProf(int ch)
{
    if(ch==1)return "Customer";
    else if(ch==2)return "Manager";
    else if(ch==3)return "Admin";
}
void customerRegister(Customer c = dummy, int rep =0)
{
        char* usr;
        prof = 1;
        if(rep == 0)c.getInfo();
        else
        {
            cout<<"Please re-enter another username or to cancel type CANCEL"<<endl;gets(usr);
            if(strcmp(usr, "CANCEL")==0)
            {
                  regStatus = -1;
                   return;
            }
            c.putUser(usr);
        }
        int regStatus2 = reg(c);
        if(regStatus2==-1)
        {
            cout<<"Username already exists."<<endl;
            register(c, 1);
        }
        else{
            cout<<"Registration Successful. Now Please login to continue"<<endl;
            regStatus=1;
            }
}
void managerRegister(Manager m = dummyM, int rep =0)
{
        char* usr;
        prof = 2;
        if(rep == 0)m.getInfo();
        else
        {
            cout<<"Please re-enter another username or to cancel type CANCEL"<<endl;gets(usr);
            if(strcmp(usr, "CANCEL")==0)
            {
                  regStatus = -1;
                   return;
            }
            m.putUser(usr);
        }
        int regStatus2 = reg(m);
        if(regStatus2==-1)
        {
            cout<<"Username already exists."<<endl;
            register(m, 1);
        }
        else{
            cout<<"Registration Successful. Now Please login to continue"<<endl;
            regStatus=1;
            }
}
void adminRegister(Admin a = dummyA, int rep =0)
{
        cout<<"Master Password "<<endl;
        char* masPass;
        gets(masPass);
        if(strcmp(masPass, "pS2R@#")){cout<<"Access Denied"<<endl;exit(0);}
        char* usr;
        prof = 1;
        if(rep == 0)a.getInfo();
        else
        {
            cout<<"Please re-enter another username or to cancel type CANCEL"<<endl;gets(usr);
            if(strcmp(usr, "CANCEL")==0)
            {
                  regStatus = -1;
                   return;
            }
            a.putUser(usr);
        }
        int regStatus2 = reg(a);
        if(regStatus2==-1)
        {
            cout<<"Username already exists."<<endl;
            register(a, 1);
        }
        else{
            cout<<"Registration Successful. Now Please login to continue"<<endl;
            regStatus=1;
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
            int ch2;
            cout<<"Are you registering as a 1.Customer\t 2.Manager\t 3.Go Back"<<endl;// 4. for admin, But it requires a master password
            cin>>ch2;
            if(ch2==1)customerRegister();
            else if(ch2==2)managerRegister();
            else if(ch==4)adminRegister();

            continue;
        }
        if(ch==1)
        {
            int ch2;
            cout<<"Login as 1.Customer\t 2.Manager\t 3.Go Back"<<endl; // 4. for admin
            cin>>ch2;
            if(ch2==3)continue;
            cout<<"Please enter username "<<endl;
            gets(user);
            if(ch2==1)prof = 1;
            else if(ch2==2)prof =2;
            else if(ch2==4)prof=3;
            else prof = -1;
            if(!(loginStatus = login(user, prof))) // I meant = only. [SOMEONE DONT CHANGE IT TO ==]
                 continue;                         // See login.cpp for better understanding
            cout<<"Successfully logged in as "<<user<<" ("showProf(prof)")<<endl;
        }

    }

}
