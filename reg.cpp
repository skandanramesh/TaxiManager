#include<fstream.h>
#include "customtime.h"
#include "customer.h"
#include "driver.h"
#include "manager.h"
#include "errcodes.h"
using namespace std;
int reg(Customer c)
{
    fstream f("Customer.dat", ios::binary|ios::in|ios::out|ios::ate), logger("log.txt", ios::in|ios::out|ios::app);
    char* dt = gettime();
    // Search if already that Customer-username is present or not
    Customer c1;
    int flag=0;
    f.seekg(0, ios::beg);// move to beg to start searching
    while(f.read((char*)&c1, sizeof(c1)))
        if(c1.getUser()==c.getUser())
    {
        flag=1;
        break;
    }
    if(flag==1){
        logger<<dt<<"Tried to register "<<c1.getUser()<<cust_already_exist<<endl;
        logger.close();
        f.close();
        return -1;    // username already exists
    }
    // If username is unique => Register
    f.seekg(0, ios::end);// move to end to start writing
    f.write((char*)&c, sizeof(c));
    f.close();
    logger<<dt<<" Successfully registered user :"<<c1.getUser()<<cust_reg<<endl;
    logger.close();
    return +1;// Registration success
}
/*
    Driver requirement is pending to be discussed
int reg(Driver d)
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
        logger<<dt<<" Customer Tried to register "<<d1.getUser()<<driver_already_exist<<endl;
        logger.close();
        f.close();
        return -1;    // username already exists
    }
    // If username is unique => Register
    f.seekg(0, ios::end);// move to end to start writing
    f.write((char*)&d, sizeof(d));
    f.close();
    logger<<dt<<" Driver Successfully registered user :"<<d1.getUser()<<driver_reg<<endl;
    logger.close();
    return +1;// Registration success
}*/
int reg(Manager m)
{
    fstream f("Manager.dat", ios::binary|ios::in|ios::out|ios::ate), logger("log.txt", ios::in|ios::out);
    char* dt = gettime();
    // Search if already that Manager-username is present or not
    Manager m1;
    int flag=0;
    f.seekg(0, ios::beg);// move to beg to start searching
    while(f.read((char*)&m1, sizeof(m1)))
        if(m1.getUser()==m.getUser())
    {
        flag=1;
        break;
    }
    if(flag==1){
        logger<<dt<<"Tried to register "<<m1.getUser()<<mgr_already_exist<<endl;
        logger.close();
        f.close();
        return -1;    // username already exists
    }
    // If username is unique => Register
    f.seekg(0, ios::end);// move to end to start writing
    f.write((char*)&m, sizeof(m));
    f.close();
    logger<<dt<<" Successfully registered user :"<<d1.getUser()<<mgr_reg<<endl;
    logger.close();
    return +1;// Registration success
}
