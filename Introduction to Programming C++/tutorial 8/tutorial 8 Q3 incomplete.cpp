#include<iostream>
using namespace std;
struct Time{
       int hours;int minutes;int seconds;};

Time setaTime( Time t)
{
     Time a;
     cout<<"enter hour";
     cin>> a.hours;
     cout<<"enter min";
     cin>> a.minutes;
     cout<<"enter sec";
     cin>> a.seconds;
     
     if( a.hours < 24)
     t.hours = a.hours;
     else
     t.hours=00;
     
     
     if( a.minutes < 60)
     t.minutes = a.minutes;
     else
     t.minutes=00;
     
     
     if( a.seconds < 24)
     t.seconds = a.seconds;
     else
     t.seconds=00;
     return t;
     
     }
     
     

    void display( Time a)
    {
         if(a.hours<24)
         cout<< a.hours;
         else
         cout<<"00:";
         
         if(a.minutes<60)
         cout<<a.minutes;
         else
         cout<<"00:";
         
         if(a.seconds< 60)
         cout<<a.seconds;
         else
         cout<< "00";
         }
         
int main()
{
    Time r;
    setaTime (  ); 
    display (w);
    system("pause");
    return 0;}
