#ifndef DRIVER_INCLUDED
#define DRIVER_INCLUDED

class driver{
  char* dr_name;
  char* car_no;
  double dr_no;
  char* location;
public: 
  void input_data()
  {
    getline(dr_name);
    getline>>car_no;
    cin>> dr_no;
    getline(location)
  }
  char* get_location()
  {
    return location;
  }
};

#endif
