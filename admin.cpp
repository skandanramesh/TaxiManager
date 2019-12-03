#include<fstream.h>
#include "customtime.h"
#include "customer.h"
#include "driver.h"
#include "manager.h"
//#include "errcodes.h"
using namespace std;
int admin(Driver d)
{
    fstream f("Driver.dat", ios::binary|ios::in|ios::out|ios::ate), logger("log.txt", ios::in|ios::out|ios::app);
    char* dt = gettime();
    // Search if already that Driver-username is present or not
    Driver d1;
    int flag=0;
    f.seekg(0, ios::beg);// move to beg to start searching
    while(f.read((char*)&d1, sizeof(d1)))
        if(d1.getUser()==d.getUser())
    {
        flag=1;
        break;
    }
    if(flag==1){
        logger<<dt<<"Tried to register "<<c1.getUser()<<"driver_already_exists"<<endl;
        logger.close();
        f.close();
        return -1;    // username already exists
    }
    // If username is unique => Register
    f.seekg(0, ios::end);// move to end to start writing
    f.write((char*)&c, sizeof(d));
    f.close();
    logger<<dt<<" Successfully registered user :"<<d1.getUser()<<" as customer"<<endl;
    logger.close();
    return +1;// Registration success
}
/*    else if(ch==2)
    {
        cout<<"Enter dr. no :"<<endl;
        unsigned long int n;
        cin>>n;
        fstream f("Drivers.dat", ios::binary|ios::ate|ios::in|ios::out);
        f.seekg(0, ios::beg);
        while(f.read((char*)&dr, sizeof(dr)))
        {
            if(dr.getNo()==n)
            {
                cout<<"You are about to dismiss the driver with the following details:"<<endl;
                dr.superDetails():
                cout<<"Are you sure: (y/n)"<<endl;
                char cho;
                cin>>cho;
                if(cho=='y')
                {
                   Driver d2;
                   int l = int(-1*sizeof(dr));
                   f.seekg(l, ios::cur);
                   while(f.seekg(-1*l, ios::cur))
                   {
                       if(!f)
                       f.read
                   }

                }
            }
            f.close();
            return;
        }
        cout<<"No Such Driver working in our Company :"<<endl;
        f.close();
        return;
    }*/
