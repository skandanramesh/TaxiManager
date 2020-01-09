#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED
#include "driver.h"
#include "customer.h"
void addDrivers(){
    cout<<"Enter Driver Details"<<endl;
    Driver d;
    d.input_data();
    writeDriver(d);
    cout<<"Driver successfully employed"<<endl;
}
void showDrivers(){

    while(1)
    {
    cout<<"1.Show Driver list. 2.Exit"<<endl;
    int ch;
    cin>>ch;
    if(ch==1)
    {
        fstream f("Drivers.dat", ios::binary|ios::ate|ios::in|ios::out);
        f.seekg(0, ios::beg);
        Driver dr;
        while(f.read((char*)&dr, sizeof(dr)))
            dr.superDetails();
    }

    else return;
    }

}
void customDetails(){
    Customer cu;
    fstream f("Customer.dat", ios::binary|ios::out|ios::in|ios::ate);
    f.seekg(0, ios::beg);
    while(f.read((char*)&cu, sizeof(cu)))
        cout<<cu.getUser()<<" "<<cu.getPass()<<endl;
    f.close();
}
void readLog(){
    char *s;
    fstream f("log.txt", ios::out);
    while(f){
    f.getline(s, 3000);
    cout<<s;
    }
}
void readSlog(){
    char *s;
    fstream f("slog.txt", ios::out);
    while(f){
    f.getline(s, 3000);
    cout<<s;
    }
}

#endif // ADMIN_H_INCLUDED
