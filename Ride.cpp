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
   //////getLoc(pickup);
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
   cout<<d"Thank You for Using Our Service :)"<<endl;

   updateDriver(dr.incRide());
   updateCustomer(a.incRide ());
   return 1;
}

void rate_ride (Customer c)
{
    cout<<"You are rating the ride with the following details:"<<endl;
    fstream f("Rides.dat", ios::binary|ios::ate|ios::in|ios::out);
    Ride dupe;
    int a = int(-1*sizeof(dupe));
    f.seekg(a, ios::cur);
    while(f.read((char*)&dupe, sizeof(dupe)))
    {
        if(dupe.isRated()==0&&dupe.retCustomer()==c)
        {
            dupe.printDetails();
            cout<<"Please rate your ride from 1 to 5 :";
            double r;
            cin>>r;
            while(1)
            {if((r==1||r==2||r==3||r==4||r==5)!=1){ cout<"Please enter from 1 to 5 only"<<endl; cin>>r;}
             else break;
            }
            dupe.rating =r;
            cout<<"Do you wish to Appreciate or complain? : 1.complaints 2.compliments 3.skip";
            cin>>dupe.ratetype;
            if(dupe.ratetype==1||dupe.ratetype==2){
                cout<<"Tell us: ";dupe.getComments();
                if(dupe.ratetype==1)cout<<"We regret for the inconvenience caused. Our staff will look into this issue and we will get back to you shortly."<<endl;
                else cout<<"Thank you for the appreciation. We hope to continue serving you a nice experience"<<endl;
            }
            cout<<"Your reviews help us serve you better. Thank you";
            c.rated();
            f.seekg(a, ios::cur);
            f.write((char*)&dupe, sizeof(dupe));
            break;
        }
`       f.seekg(2*a, ios::cur);
    }
    f.close();

}

