#ifndef RIDES_INCLUDED
#define RIDES_INCLUDED
#include<stdlib.h>
#include "customtime.h"
#include "driver.h"
#include "customer.h"
#define STD_RATE 10
double peakfactor=1;
class Ride
{
    private:
      Customer c;
      Driver d;
      char* bookingTime;
      Location pickup, drop;
      double fare;
      double rating;
      char* comments;

    public:
        int ratetype;// 1-complained 2-appreciated 3-skipped
      Ride(Customer c2, Driver d2, Location p, Location d)
      {
        rating=-1;
        comments="";
        c = c2;
        d = d2;
        pickup =p;
        drop = d;
        fare=dist(p, d)*STD_RATE*peakfactor*(random(5)/10+1);
        cout<<"Expected fare is "<<fare<<endl;
      }

      void bookRide(){
          bookingTime = gettime();
          ofstream fout("Rides.dat", ios::binary|ios::ate);
          fout.write((char*)&r, sizeof(Ride));
          fout.close();
      }
      void printDetails()
      {
        cout<<"Customer Name : "<<c.getUser()<<endl;
        cout<<"Riding From "<<pickup.getFullLoc()<<" To "<<drop.getFullLoc()<<" On "<<bookingTime<<" with "<<d.getName()<<" On "<<d.getveh()<<endl;
        cout<<"For an expected fare of "<<fare<<endl;
        cout<<"Driver details :"<<endl;
        d.printDetails();
      }
      void shortDetails(){
        cout<<"Rided From "<<pickup.getArea()<<" To "<<drop.getArea()<<" On "<<bookingTime<<" with "<<d.getName()<<" On "<<d.getveh()<<endl;
        cout<<"For a fare of "<<fare<<" Rated :"<<rating<<endl;
      }
      void fullDetails(){
        cout<<"Rided From "<<pickup.getArea()<<" To "<<drop.getArea()<<" On "<<bookingTime<<" with "<<d.getName()<<" On "<<d.getveh()<<endl;
        cout<<"For a fare of "<<fare<<" Rated :"<<rating<<endl;
        cout<<"Driver details :"<<endl;
        d.printDetails();
      }
      int isRated(){
          return (rating==-1)?0:1;
      }
      Customer retCustomer(){return c};
      void getComments(){gets(comments);}
};

#endif
