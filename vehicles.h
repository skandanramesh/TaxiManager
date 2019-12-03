#ifndef VEHICLE_INCLUDED
#define VEHICLE_INCLUDED
#include "dates.h"
class Vehicle
{
protected:
   char* vno, *rcno;
   Date insRenewal;
   double basic;
   char* modelname;
   char* manu;
   int isAc;
   char* vehType;
   int vehTypeValue; //1Car 2 Bike
  public:
     virtual void printDetails ()=0; // pure virtual fn
     virtual void getDetails ()=0;
     virtual void printVehName()=0;
     int getVehType(){return vehTypeValue;}
};
class Car :public Vehicle
{
public:
   Car(){vehType="Car";vehTypeValue=1;}
   void printDetails (){
   }
   void getDetails (){
       cout<<"Enter vehicle no, rc no, insurance renewal date(dd-mm-yyyy), basic, modelname, manufacturer, isAc(1-Ac 0-No)"<<endl;
       gets(vno);gets(rcno);insRenewal.acceptdate();cin>>basic;gets(modelname);gets(manu);cin>>isAc;
   }
   void printVehName(){
       cout<<vehType<<":"<<modelname<<" by "<<manu<<" Vehicle no. : "<<vno<<endl;
   }
};
class Bike:public Vehicle
{
public:
   Bike(){vehType="Bike";isAc=0;vehTypeValue=2;}
   void printDetails (){
   }
   void getDetails (){
       cout<<"Enter vehicle no, rc no, insurance renewal date(dd-mm-yyyy), basic, modelname, manufacturer"<<endl;
       gets(vno);gets(rcno);insRenewal.acceptdate();cin>>basic;gets(modelname);gets(manu);
   }
   void printVehName(){
       cout<<vehType<<":"<<modelname<<" by "<<manu<<" Vehicle no. : "<<vno<<endl;
   }
};
#endif
