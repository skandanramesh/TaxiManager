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
    public:
      Ride(Customer c2, Driver d2, Location p, Location d)
      {
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
        d.printDetails();
      }
};

#endif
