
#include <iostream>
using namespace std;
 
class threed{
      public:
             
             threed(int=0,int=0,int=0);
             void setx(int);
             void sety(int);
             void setz(int);
             void display();
             void copy(threed );
             threed operator +(threed );     
      private:
              int x ,y,z ;};
              
threed::threed(int a=0,int b=0,int c=0){
                  x =a; y=b; z=c;}
void threed :: setx(int a){
     x =a;}
     
void threed :: sety(int a){
     y =a;}
     
void threed :: setz(int a){
     z =a;}
     
void threed::display(){
     cout << "x :" << x << "y : " << y << "z : " << z;} 

void threed::copy(threed a){
     x = a.x;
     y = a.y;
     z = a.z;}

threed threed :: operator +( threed a){
     threed temp;
     temp.x = x + a.x;
     temp.y = y + a.y;
     temp.z = z + a.z;
     return temp;}
     
int main()
{
  threed q(7,8,6);
  q.display();
  q.setx(1);
  q.sety(2);
  q.setz(3);
  q.display();
  threed r(),w(11,22,32);
  r = w + q;
  r.display();
       
  system("pause");
  return 0;  
}

