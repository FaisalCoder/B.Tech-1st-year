
#include <iostream>
using namespace std;
 
class threed{
      public:
             threed(int,int,int);
             void setx(int);
             void sety(int);
             void setz(int);
             void display();
      private:
              int x ,y ,z;};
              
threed::threed(int a,int b,int c){
                   setx(a);
             sety(b);
              setz(c);}
void threed :: setx(int a){
     x =a;}
void threed :: sety(int a){
     y =a;}
void threed :: setz(int a){
     z =a;}
     void threed::display(){
          cout << "x :" << x << "y : " << y << "z : " << z;} 
int main()
{
  threed q(7,8,6);
  q.display();
  q.setx(1);
  q.sety(2);
  q.setz(3);
  q.display();
       
  system("PAUSE");
  return 0;  
}

