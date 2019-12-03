#ifndef DATES_H_INCLUDED
#define DATES_H_INCLUDED
struct Date
 {
  int year;
  int month;
  int date;
  void acceptdate()
  {
   cout<<"Enter date: ";
   cin>>date;
   cout<<"Enter month number: ";
   cin>>month;
   cout<<"Enter year: ";
   cin>>year;
  }
  void displaydate()
  {
   cout<<date<<"/"<<month<<"/"<<year<<'\n';
  }
 };

#endif // DATES_H_INCLUDED
