#ifndef RIDES_INCLUDED
#define RIDES_INCLUDED
#include "customtime.h"
#include "driver.h"
#include "customer.h"
using namespace std;
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
        bookingTime - gettime();
      }
      void printDetails()
      {
        cout<<"Customer Name : "<<c.getUser()<<endl;
        d.printDetails();
      }
};

#endif
