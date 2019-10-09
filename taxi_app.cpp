#include<fstream.h>
#include<stdio.h>
#include<process.h>
void taxi_booking(customer a)
{int ch=0;ch1=0,ch2=0,ch3=0;driver b,c;//must make a constructor for driver with location=infinity_point//
 char s[50]; 
 cout<<"1.Ride now/n2.Exit app\n";
 cout<<"enter choice:";cin>>ch1;
 if(ch==1)
 {cout<<"1.Are you at home?\n2.Are you elsewhere?\n3.exit app\n";
  cout<<"enter choice:";cin>>ch2;
if(ch2==1)
{re:cout<<"enter drop location:";
 cout<<"1.do you want to confirm booking?\n2.You want to change drop location?\n3.exit app\n";
 cout<<"enter choice:";cin>>ch3;
 if(ch3==1)
 {cout<<"booking confirmed\n";
  cout<<"driver details:\n";
  ifstream afin("drivers.dat",ios::binary);
  afin.seekg(ios::beg);
  if(!afin){cout<<"sorry driver not available, try again\n";goto re;}
  while(afin.read((char*)&b,sizeof(b)))
  { if(b.getlocation_distance()<c.getlocation_distance()) c=b;}
  cout<<c.put_details();cin>>ch;//functions as getch()//
  afin.close();
  cout<<"you have been dropped successfully\ndescribe your ride:";
  rere:ofstream afout("complaints.dat",ios::binary|ios::app);
  if(!afout){goto rere;}
  gets(s);afout.write((char*)s,sizeof(s));//team, is this statement correct syntactically?//
