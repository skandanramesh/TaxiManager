#ifndef LOCATIONS_INCLUDED
#define LOCATIONS_INCLUDED
#include<math.h>
#include<iostream.h>
struct Location
{
  char address[300];
  int area;
  int x, y;
  void setLoc();
  void setLoc(int ar, int x2, int y2)
  {
      strcpy(address, "");
      area = ar;
      x= x2;
      y= y2;
  }
  char* getArea();
  char* getFullLoc(){return address;}
};
void Location::setLoc()
  {
  cout<<"Enter address"<<endl;
  cin.ignore();
  cin.getline(address, 300);
  cout<<"Enter area"<<endl;
  cout<<" 1.Chetpet 2.Kilpauk 3. Nungambakkam 4.T Nagar 5.Guindy 6.Chromepet 7.Tambaram 8.Velacherry"<<endl;
  cin>>area;
  int c = area;
  if(c==1){x=y=0;}
  if(c==2){x=y=1;}
  if(c==3){x=1;y=2;}
  if(c==4){x=3;y=2;}
  if(c==5){x=4;y=3;}
  if(c==6){x=7;y=4;}
  if(c==7){x=7;y=7;}
  if(c==8){x=5;y=4;}
}
char* Location::getArea()
  {
      int c = area;
    if(c==1)return "Chetpet";
    if(c==2)return "Kilpauk";
    if(c==3)return "Nungambakkam";
    if(c==4)return "T Nagar";
    if(c==5)return "Guindy";
    if(c==6)return "Chromepet";
    if(c==7)return "Tamabram";
    if(c==8)return "Velacherry";
    return "Chennai";
  }
typedef Location Loc;

double dist(Loc l1, Loc l2)
{
  return sqrt( pow((l1.x-l2.x),2)+ pow((l1.y-l2.y), 2));
}

#endif
