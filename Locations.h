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
    loc1.setLoc("Anna Nagar", 10, 0);
    loc2.setLoc("T Nagar", -10, 0);
}
double dist(Loc l1, Loc l2)
{
  return sqrt( pow(l1.x-l2.x,2) + pow(l1.y-l2.y, 2));
}
void getLoc(Loc& l1)
{
  gets(l1.locationName);
  std::cin>>l1.x>>l1.y;
}
#endif
