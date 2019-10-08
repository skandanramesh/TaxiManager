#include<fstream.h>
#include "customtime.h"
class Session
{
    char* stime, etime;
    char* user;
    int isopen; // 0 if session ended 1 if session running
public:
    Session(char* u)
    {
        user = u;
        stime = gettime();
        isOpen = 1;
    }
    int endSession()
    {
        isOpen = 0;
        etime = gettime();
        fstream logger("slog.txt", ios::in|ios::out|ios::app);
        logger<<stime<<" to "<<etime<<" username: "<<user<<endl;
        logger.close();
        return 1; // session ended successfully
    }

}currentSession;

Session nullSession("");

Session validateUser(char* user, char* pass)
{
    fstream f;
    f.open("Customer.dat", ios::in|ios::out|ios::binary|ios::ate);}
    f.seekg(0, ios::beg);
    Customer c;
    int flag = 0;
    while(f.read((char*)&c, sizeof(c))
        if(c.getUser()==user&&c.getPass()==pass)
            flag=1;
    if(flag==0) return nullSession; // incorrect user/pass
    return Session(user);
}

int login(char* user)
{
re:
    cout<<"1.Login 2.Go Back"<<endl;
    int ch;
    cin>>ch;
    if(ch==2)return 0;
    cout<<"Please enter your Username and password "<<endl;
    char* pass;
    gets(user);
    gets(pass);
    currentSession = validateUser(user, pass);
    if(currentSession==nullSession)cout<<"Incorrect username or password. Please try again "<<endl;
        goto re;
    return 1;
}
int logout()
{
    if(currentSession==nullSession||currentSession.isOpen()==0)
        return -1;
    currentSession.endSession();
    cout<<"Bye. See you later"<<endl;
}
