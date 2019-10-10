#include<fstream.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
void taxi_booking(customer a)
{int ch=0;ch1=0,ch2=0,ch3=0,ch4=0,ch5=0,ch6=0;
 driver b,c;//must make a constructor for class driver with location=infinity_point//
 char s[50],s1[50],s2[50],s3[50];
 location d;
 int dist=0,dist1=0,dist2=0;
 cout<<"1.Ride now/n2.Exit app\n";
 cout<<"enter choice:";cin>>ch1;
 if(ch1==1)
 {
  do
  {
   cout<<"1.Are you at home?\n2.Are you elsewhere?\n3.Exit app\n";
   cout<<"enter choice:";cin>>ch2;
   if(ch2==1)
   {do
    {re: cout<<"enter drop location:";gets(s2);
    u: ifstream efin("locations.dat",ios::binary);//must have a file to store list of locations//
    efin.seekg(ios::beg);
    if(!efin){cout<<"sorry technical error/n1.refresh/n2.exit app/n";
              cout<<"enter choice:";cin>>ch;if(ch==1)goto u;else exit(0);}
    while(efin.read((char*)&d,sizeof(d))
    {if(strcmpi(d.getlocation_name(),s2)==0) dist1==d.getlocation_distance();//getlocation_distance() is a member function of location//
    }
    if(dist1==0) {cout<<"location not found/n";
    cout<<"1.enter another location\n2.exit app\n";
    cout<<"enter choice:";cin>>ch5;
                  if(ch5==2)exit(0);}
          }while(ch5==1)
          
    efin.close();
          if(ch5!=0)cout<<"fatal error";exit(0);
    cout<<"1.do you want to confirm booking?\n2.You want to change drop location?\n4.you want to restart booking\n3.exit app\n";
    cout<<"enter choice:";cin>>ch3;
          if(ch3==4)
          {continue;}
    if(ch3==1)
    { cout<<"booking confirmed\n";
      cout<<"driver details:\n";
      l: ifstream afin("drivers.dat",ios::binary);
      afin.seekg(ios::beg);
      if(!afin){cout<<"sorry technical error/n1.refresh/n2.exit app/n";
              cout<<"enter choice:";cin>>ch;if(ch==1)goto l;else exit(0);
    }
    while(afin.read((char*)&b,sizeof(b)))//getlocation_distance() is defined differently and accordingly for customers and drivers//
    { if(b.getlocation_distance(a.getlocation_distance())<c.getlocation_distance(a.getlocation_distance())) c=b;
    }
     if(strcmpi(c.location,"infinity_point")==0) {cout<<"sorry driver not found";exit(0);}
    cout<<c.put_details();cin>>ch;//functions as getch()//
    afin.close();
    cout<<"you have been dropped successfully\ndescribe your ride:";
    rere:ofstream afout("complaints.dat",ios::binary|ios::app);//must have a file to store complaints for manageers to read//
    if(!afout){cout<<"sorry technical error/n1.refresh/n2.exit app/n";
               cout<<"enter choice:";cin>>ch;if(ch==1)goto rere;else exit(0);
              }
    gets(s);afout.write((char*)s,sizeof(s));//team, is this statement correct syntactically?//
    afout.close();
    cout<<"thank you for your feedback";cin>>ch;
    cout<<"1.Ride again\n2.Exit app\n";
    cout<<"enter choice:";cin>>ch1;
   }
   else if(ch3==2)
   { goto re;
   }
   else if(ch3==3) exit(0);
  }
  else if(ch2==2)
    {r: cout<<"enter your location:";gets(s1);//we will need a small class 'location'//
     s: ifstream bfin("locations.dat",ios::binary);//must have a file to store list of locations//
     bfin.seekg(ios::beg);
     if(!bfin){cout<<"sorry technical error/n1.refresh/n2.exit app/n";
              cout<<"enter choice:";cin>>ch;if(ch==1)goto s;else exit(0);}
     while(bfin.read((char*)&d,sizeof(d))
           {if(strcmpi(d.getlocation_name(),s1)==0) dist==d.getlocation_distance(); }
          if(dist==0) {cout<<"location not found/n";
           cout<<"1.enter another location\n2.exit app\n";
           cout<<"enter choice:";cin>>ch4;
           if(ch4==1) goto r;
           else exit(0);}
           bfin.close();
           rer:cout<<"enter drop location:"; gets(s3);
            v: ifstream fin("locations.dat",ios::binary);//must have a file to store list of locations//
     fin.seekg(ios::beg);
     if(!fin){cout<<"sorry technical error/n1.refresh/n2.exit app/n";
              cout<<"enter choice:";cin>>ch;if(ch==1)goto v;else exit(0);}
     while(fin.read((char*)&d,sizeof(d))
           {if(strcmpi(d.getlocation_name(),s3)==0) dist2==d.getlocation_distance(); }
          if(dist2==0) {cout<<"location not found/n";
           cout<<"1.enter another location\n2.exit app\n";
           cout<<"enter choice:";cin>>ch6;
           if(ch6==1) goto rer;
           else exit(0);}
           fin.close();
  cout<<"1.do you want to confirm booking?\n2.You want to change drop location?\n3.exit app\n";
  cout<<"enter choice:";cin>>ch3;
  if(ch3==1)
  {cout<<"booking confirmed\n";
   cout<<"driver details:\n";
   z: ifstream cfin("drivers.dat",ios::binary);
   cfin.seekg(ios::beg);
   if(!cfin){cout<<"sorry technical error/n1.refresh/n2.exit app/n";
              cout<<"enter choice:";cin>>ch;if(ch==1)goto z;else exit(0);}
   while(cfin.read((char*)&b,sizeof(b)))//getlocation_distance() is defined differently and accordingly for customers and drivers//
   { if(b.getlocation_distance(dist)<c.getlocation_distance(dist)) c=b;}
   cout<<c.put_details();cin>>ch;//functions as getch()//
   cfin.close();
   cout<<"you have been dropped successfully\ndescribe your ride:";
   t:ofstream dfout("complaints.dat",ios::binary|ios::app);//must have a file to store complaints for manageers to read//
   if(!dfout){cout<<"sorry technical error/n1.refresh/n2.exit app/n";
              cout<<"enter choice:";cin>>ch;if(ch==1)goto t;else exit(0);}
   gets(s);dfout.write((char*)s,sizeof(s));//team, is this statement correct syntactically?//
   dfout.close();
   cout<<"thank you for your feedback";cin>>ch;
   cout<<"1.Ride again\n2.Exit app\n";
   cout<<"enter choice:";cin>>ch1;
  }  
  else if(ch2==3)exit(0);
  }while(ch1==1);
 }
 else if(ch1==2) exit(0);
}
           }
