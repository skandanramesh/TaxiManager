#include<stdio.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<iomanip.h>
#include<stdlib.h>
int main() {
 clrscr();
 int ch=0,ch1=0,ch2=0,k=0;
 admin dummy_admin;
 driver dummy_driver;
 manager dummy_manager;
 while(ch!=3)
 {cout<<"1.enter as admin/n2.enter into application/n3.end program/n";
 cout<<"enter choice:";cin>>ch;
 if(ch==1)
 {k=dummy_admin.login();
  cout<<"1.add new location\n2.add new driver\n;
  cout<<"3.view returns details\n4.update a driver's details\n;
  if(ch==1)
  {char locn[30];int x1,y1;
   cout<<"enter location name:";gets(locn);
   cout<<"enter coordinates:";cin>>x1>>y1;
  }
  if(ch==2)
  {admin.driver.putdetails();}
  if(ch==3)
  {admin.getreturns();}
  if(ch==4)
  {admin.driver_update();}
 }
 else if(ch==2)
 {cout<<"welcome to our taxi management application";
  cout<<"1.book a ride\n2.exit application\n";
  cout<<"enter choice:";cin>>ch1;
  if(ch1==2)continue;
  else if(ch1==1)
  {cout<<"
 }
 getch();
 return 0;
}
