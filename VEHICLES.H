#ifndef VEHICLE_INCLUDED
#define VEHICLE_INCLUDED
#include "dates.h"
class Vehicle
{
protected:
   char vno[30];
   double basic;
   char modelname[30];
   char manu[30];
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
       cout<<"Enter vehicle no, basic, modelname, manufacturer, isAc(0no 1yes)"<<endl;
       cin.ignore();
       gets(vno);
       cin>>basic;
      // cin.getline(modelname,30);
       //cin.getline(manu,30);
       cin>>isAc;
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
	   cout<<"Enter vehicle no, basic, modelname, manufacturer, isAc(0no 1yes)"<<endl;
       cin.getline(vno, 30);
       cin>>basic;
       cin.getline(modelname,30);
       cin.getline(manu,30);
   }
   void printVehName(){
       cout<<vehType<<":"<<modelname<<" by "<<manu<<" Vehicle no. : "<<vno<<endl;
   }
};
#endif
