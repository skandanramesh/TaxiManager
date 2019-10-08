#include<stdio.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<iomanip.h>
#include<stdlib.h>
int main() {
 clrscr();
 int ch,ch1,ch2,k;
 admin dummy_admin;
 cout<<"1.enter as admin/n2.enter into application/n3.end program/n";
 cout<<"enter choice:";cin>>ch;
 if(ch==1)
 {start: k=dummy_admin.login();
  if(k!=1){cout<<"details mismatch, retry";goto start;}
  else cout<<"1.add new location\n2.add new driver\n3.add new manager\n";
  cout<<"4.view returns details\n5.update a manager's details\n6.update a driver's details
 getch();
 return 0;
}
