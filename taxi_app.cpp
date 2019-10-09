#include<fstream.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
void taxi_booking(customer a)
{int ch=0;ch1=0,ch2=0,ch3=0;driver b,c;//must make a constructor for driver with location=infinity_point//
 char s[50],s1[50];location d;int dist; 
 cout<<"1.Ride now/n2.Exit app\n";
  cout<<"enter choice:";cin>>ch1;
  if(ch1==1)
  {
   do{
    cout<<"1.Are you at home?\n2.Are you elsewhere?\n3.exit app\n";
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
   while(afin.read((char*)&b,sizeof(b)))//getlocation_distance() is defined differently and accordingly for customers and drivers//
   { if(b.getlocation_distance(a.getlocation_distance())<c.getlocation_distance(a.getlocation_distance())) c=b;}
   cout<<c.put_details();cin>>ch;//functions as getch()//
   afin.close();
   cout<<"you have been dropped successfully\ndescribe your ride:";
   rere:ofstream afout("complaints.dat",ios::binary|ios::app);//must have a file to store complaints for manageers to read//
   if(!afout){goto rere;}
   gets(s);afout.write((char*)s,sizeof(s));//team, is this statement correct syntactically?//
   afout.close();
   cout<<"thank you for your feedback";cin>>ch;
   cout<<"1.Ride again\n2.Exit app\n";
   cout<<"enter choice:";cin>>ch1;}
   else if(ch3==2)
   {goto re;}
  else if(ch3==3) exit(0);
 }
    else if(ch2==2)
    {r: cout<<"enter your location:";gets(s1);//we will need a small class 'location'//
     rerere: ifstream bfin("locations.dat",ios::binary);//must have a file to store list of locations//
     bfin.seekg(ios::beg);
     if(!bfin){goto rerere;}
     while(bfin.read((char*)&d,sizeof(d))
           {if(strcmpi(d.getlocation_name(),s1)==0) dist==d.getlocation_distance();
            else cout<<"location not found/n";goto r;}
  }while(ch1==1);
 }
    else if(ch==2) exit(0);
   }
