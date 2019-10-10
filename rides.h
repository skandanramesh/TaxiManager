#ifndef RIDES_INCLUDED
#define RIDES_INCLUDED
#include "customtime.h"
class Ride
{
    private:
      Customer c;
      Driver d;
      char* bookingTime;
    public:
      Ride(Customer c2, Driver d2)
      {
        c = c2;
        d = d2;
        bookingTime - getTime();
      }
      void printDetails()
      {
        cout<<"Customer Name : "<<c.getUser()<<endl;
        d.printDetails();
      }
};

#endif
