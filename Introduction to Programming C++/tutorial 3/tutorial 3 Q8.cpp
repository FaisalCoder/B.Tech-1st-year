//program to evaluate roots of a quadratic equation
#include <iostream>
#include <cmath>

using namespace std;

int main()
{float a,b,c;
cout << "enter a = ";
cin >> a;
cout << "enter b = ";
cin >> b;
cout << "enter c = ";
cin >> c;
float r1,r2,d;
d = b*b - 4*a*c;

if ( d >= 0 )
{
     r1 = (- b + sqrt(d) )/(2*a) ;
     r2 = (- b - sqrt(d) )/(2*a) ;
        cout << "root 1 = " << r1 << endl;
        cout << "root 2 = " << r2 << endl;
        cout << "roots are real ";
}
else if ( a > 0 ) 
{  
    cout << "root 1 = " << - b/2/a << "+ i" << (sqrt(-d))/2/a << endl;
    cout << "root 2 = " << - b/2/a << "- i" << (sqrt(-d))/2/a <<endl;
    cout << "roots are imaginary ";
}    
else if ( a < 0 ) 
{  
    cout << "root 1 = " << - b/2/a << "- i" << (sqrt(-d))/2/abs(a) << endl;
    cout << "root 2 = " << - b/2/a << "+ i" << (sqrt(-d))/2/abs(a) <<endl;
    cout << "roots are imaginary " << endl;
}    
system ("PAUSE");
return 0;
}
