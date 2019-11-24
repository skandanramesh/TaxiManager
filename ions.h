#ifndef LOCATIONS_INCLUDED
#define LOCATIONS_INCLUDED
#include<math.h>
#include<stdio.h>
#include<iostream.h>
struct Location
{
  char* locationName;
  int x, y;
  void setLoc(char* LocName, int x2, int y2)
  {
      locationName = LocName;
      x= x2;
      y= y2;
  }
};
typedef Location Loc;
//typedef  Location cLoc;
Loc ORIGIN, loc1, loc2;
void init_locs()
{
    ORIGIN.setLoc("ORIGIN", 0, 0);
    loc1.setLoc("Airport", 0, 0);
    loc2.setLoc("Alandur", 30, 25);
    loc3.setLoc("Ashok Nagar", 30, 55);
    loc4.setLoc("Vadapalani", 30, 70);
    loc5.setLoc("CMBT", 25, 85);
    loc6.setLoc("Thirumangalam", 20, 100);
    loc7.setLoc("Anna nagar",40 , 100);  
    loc8.setLoc("Kilpauk", 65, 80);
    loc9.setLoc("Egmore", 90, 90); 
    loc10.setLoc("Chennai Central", 100, 100);
    
}
double dist(Loc l1, Loc l2)
{
  return sqrt( pow(l1.x-l2.x,2) + pow(l1.y-l2.y, 2));
}

void getLoc(Loc& l1)
{
  gets(l1.locationName);
  cin>>l1.x>>l1.y;
}
#endif
