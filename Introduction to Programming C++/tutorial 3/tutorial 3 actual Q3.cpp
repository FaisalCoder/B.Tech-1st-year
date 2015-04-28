/* program to find first n terms of a series tutorial 3 Q3 */
#include <iostream>
#include <cmath>
using namespace std;

int fact(int x)
{
   int fact = 1;
   for( int i = 1; i <= x; i++)
   fact *= 1;
   return fact;
}
  
int main()
{
    float sum = 1;
    for( double i = 1; i <= 20; i++)
    sum += (i)* pow(-1 ,i)/fact(i);
    cout << "Sum of the first 20 term(s) of the series = " << sum << endl;
    system("PAUSE");
    return 0;
}   
