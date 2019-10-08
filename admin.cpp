#include<fstream.h>
#include "customtime.h"
#include "customer.h"
#include "driver.h"
#include "manager.h"
#include "errcodes.h"
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
        logger<<dt<<"Tried to register "<<c1.getUser()<<driver_already_exists<<endl;
        logger.close();
        f.close();
        return -1;    // username already exists
    }
    // If username is unique => Register
    f.seekg(0, ios::end);// move to end to start writing
    f.write((char*)&c, sizeof(d));
    f.close();
    logger<<dt<<" Successfully registered user :"<<d1.getUser()<<cust_reg<<endl;
    logger.close();
    return +1;// Registration success
}
