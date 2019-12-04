#ifndef SUPPORT_INCLUDED
#define SUPPORT_INCLUDED
#include "customtime.h"
#include "customer.h"
#include "rides.h"
#include "locations.h"
#include<fstream>

void support(Customer c)
{
    cout<<"How many last rides do you wish to search from"<<endl;
    int l;
    cin>>l;
    fstream f("Rides.dat" , ios::ate|ios::binary|ios::in|ios::ate);
    Ride ri;
    int i=1;
    cout<<"Here are some of your previous rides . Please select one to continue "<<endl;
    f.seekg(int(-1*sizeof(ri)), ios::cur);
    while(f.read((char*)&ri, sizeof(ri))&&i<=l) {
        if(ri.retCustomer().getUser()==c.getUser())
            cout<<i++<<". ";ri.shortDetails();
        f.seekg(2*int(-1*sizeof(ri)), ios::cur);
    }
    i--;
    if(i==0){cout<<"Looks like you haven't rided even once. Ride with us to see your rides here."<<endl;return;}
    cin>>i;int k=1;
    f.seekg(int(-1*sizeof(ri)), ios::end);
    while(f.read((char*)&ri, sizeof(ri)))
    {
        if(ri.retCustomer().getUser()==c.getUser())
            if(k==i){
                while(1){
                    cout<<"What do you wish to do: 1.View full ride details. 2.Support 3. Return"<<endl;
                    int ch;
                    cin>>ch;
                    if(ch==1)ri.fullDetails();
                    else if(ch==2){
                            ri.getComments();
                            cout<<"Our Customer Care Executive will contact you shortly"<<endl;
                             f.seekg(int(-1*sizeof(ri)), ios::cur);
                             f.write((char*)&ri, sizeof(ri));
                            }
                    else {f.close();return;}
                }
            }
            else k++;
        f.seekg(2*int(-1*sizeof(ri)), ios::cur);
    }
    f.close();
}

#endif // SUPPORT_INCLUDED
