#include<fstream.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include "driver.h"
#include "locations.h"
#include "rides.h"
int taxi_booking(customer a)
{
    Loc pl;
    cout<<" 1. Pickup from default address \n2.Pickup from different address \n3.Go Back"<<endl;
    int ch;
    cin>>ch;
    if(ch==1)
      pl = a.getLocation();
    else if(ch==2)
      getLoc(pl);
    else return 0;
    Driver dr = nearestDriver(pl);
    if(dr == nullDriver){cout<<"Location currently unservicable"<<endl;return 0;}
    cout<<"Booking confirmed. Ride Details :"<<endl;
    Ride r(a, dr);
    r.printDetails();
    ofstream fout("Rides.dat", ios::binary|ios::ate);
    fout.write((char*)&r, sizeof(Ride));
    fout.close();
    cout<<"Thank You for Using Our Service xD"<<endl;
    d.incRide();
    return 1;
}
    
