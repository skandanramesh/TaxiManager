class complaint
{ char* userid;
  char complaint[500];
public:
void complain()
{cout<<"enter your user id";
//Call function to check if user id exists
cout<<"Enter your complaint in not more than 500 words"<<endl;
gets(complaint);
cout<<"Our staff will look into this issue and try to contact you through your account. Inconvenience caused is regretted. "<<endl;
return;
}
};
