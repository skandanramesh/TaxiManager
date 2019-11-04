#ifndef VEHICLE_INCLUDED
#define VEHICLE_INCLUDED
class Vehicle
{
protected:
   char* vno, rcno;
   date insRenewal;   
   double basic;
   char* modelname;
   char* manu;
   int isAc;
   char* vehType;
  public:
     virtual void printDetails ()=0; // pure virtual fn
     virtual void getDetails ()=0;
};
class Car :public Vehicle
{
public:
   Car(){vehType="Car";}
   void printDetails (){
   }
   void getDetails (){
   }
};
#endif
