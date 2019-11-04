#ifndef LOCATIONS_INCLUDED
#define LOCATIONS_INCLUDED
#include<math.h>
struct Location
{
  char* address;
  int area;
  int x, y;
  void getLoc()
{
  cout<<"Enter address"<<endl;
  gets(address);
  cout<<"Enter area"<<endl;
  cout<<" 1.Chetpet 2.Kilpauk 3. Nungambakkam 4.T Nagar 5.Guindy 6.Chromepet 7.Tambaram"<<endl;
  cin>>area;
  if(c==1){x=y=0;}
  if(c==2){x=y=1;}
  if(c==3){x=1;y=2;}
  if(c==4){x=3;y=2;}
  if(c==5){x=4;y=3;}
  if(c==6){x=7;y=4;}
  if(c==7){x=7;y=7;}
}
};
typedef Location Loc;
double distance(Loc l1, Loc l2)
{
  return sqrt( pow(l1.x-l2.x,2), pow(l1.y-l2.y), 2);  
}
#endif
