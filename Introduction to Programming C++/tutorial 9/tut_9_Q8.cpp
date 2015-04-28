#include<iostream>
#include<cmath>
using namespace std;
 
class point
{
      public:
             float x,y;
             point():x(0),y(0){}
             point(float x1 ,float y1):x(x1),y(y1){}
             
             friend ostream& operator<<(ostream &,point);
             float operator-(point a)
             {
                   float d;
                   d = sqrt((x-a.x)*(x-a.x)+(y-a.y)*(y-a.y));
                   return d;
             } 
             
             void shift(float r , float theta)
             {
                  x = x + r*cos(theta);
                  y = y + r*sin(theta);
             }
             
             void operator=(point b)
             {
                  x= b.x;
                  y = b.y;
             }
};

ostream& operator<<(ostream & output,point q)
{
         output << "[  " << q.x << " , " << q.y << " ]" << endl;
         return output;
}

int main()
{
    point a(2.3,5.0),d(4,6);   
    cout << a << d << endl;
    cout << (a-d) << endl;
    a.shift(1.0,0.0);
    cout << a;
    
    system("pause");
    return 0;
}
