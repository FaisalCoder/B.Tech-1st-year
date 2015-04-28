#include<iostream>
using namespace std;
 
class figure{
      protected:
                double x,y;
      public :
             void set_dim(double i , double j){
                  x=i;
                  y=j;}
                  virtual void show()=0;};
             
class triangle : public figure
{ 
      virtual void show()
      {double area = x*y/2;
      cout << area << endl;}};
class rectangle : public figure
{ 
      virtual void show()
      {double area = x*y;
      cout << area << endl;}};
             
             
             
int main(){
    triangle a;
    rectangle b;
    figure* p=&a;
    p->set_dim(1,2);
    p->show();
    p=&b;
    p->set_dim(1,4);
    p->show();
    
    system("pause");
    return 0;}
                 
                  
                  
