#include<fstream.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include "driver.h"
#include "customer.h"
#include "locations.h"
#include "rides.h"
int taxi_booking(Customer a)
{
   cout<<" 1. Pickup from default address \n2.Pickup from different address \n3.Go Back"<<endl;
   Loc pickup;
   getLoc(pickup);
   int ch;
   cin>>ch;
   if(ch==1)pickup = a.getLocation();
   else if(ch==2)pickup.getLoc();
   else return 0;
   Driver dr = nearestDriver(pickup);
   if(dr.isNull()){cout<<"Location currently unservicable"<<endl;return 0;}
   cout<<"Enter Drop location"<<endl;
   Loc drop;
   drop.getLoc();
   if(dist(pickup, drop)>10*MAX_DISTANCE)
   {cout<<"Ride distance too big. We aren't servicing very long drives currently. Sorry"<<endl;return 0;} 
   Ride r(a, dr, pickup, drop);
   cout<<"Confirm Booking?(0-no. any other number-yes)"<<endl;
   cin>>ch;
   if(ch==0)return 0;
   cout<<"Booking confirmed. Ride Details :"<<endl;
   r.bookRide();
   r.printDetails();
   cout<<"Thank You for Using Our Service :)"<<endl;
    
   updateDriver(dr.incRide());
   updateCustomer(a.incRide ());
   return 1;
}

void rate_ride (Customer c)
{
    //Todo

}
