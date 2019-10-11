#include<fstream>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include "driver.h"
#include "customer.h"
#include "locations.h"
#include "rides.h"
using namespace std;
int taxi_booking(Customer a)
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
    if(dr.isNull()){cout<<"Location currently unservicable"<<endl;return 0;}
    cout<<"Booking confirmed. Ride Details :"<<endl;
    Ride r(a, dr);
    r.printDetails();
    ofstream fout("Rides.dat", ios::binary|ios::ate);
    fout.write((char*)&r, sizeof(Ride));
    fout.close();
    cout<<"Thank You for Using Our Service xD"<<endl;
    dr.incRide();
    a.incRide ();
    return 1;
}

void rate_ride (Customer c)
{
    //Todo

}
