#ifndef LOCATIONS_INCLUDED
#define LOCATIONS_INCLUDED
struct Location
{
  char* locationName;
  int x, y;
};
typedef Location Loc;
typedef const Location cLoc;
const cLoc loc1
const cLoc loc1{"Anna Nagar",   -10, 0);
const cLoc loc2{"T Nagar", 10, 0);    
double distance(Loc l1, Loc l2)
{
  return sqrt( pow(l1.x-l2.x,2), pow(l1.y-l2.y), 2);  
}

#endif
