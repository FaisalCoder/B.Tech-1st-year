//tut7 Q11
#include <iostream>
using namespace std;

int square(int a)
{return a*a;}

int cube(int a)
{return a*a*a;}

int sum(int(*pf)(int x),int n)
{
    int sum=0;
    for(int i=0; i<= n; i= i+2)
    sum += (*pf)(i);
    return sum;
}
int main()
{
    int a;
    cout << "Enter a number " << endl;
    cin >> a;
    cout << sum (square,a)<< endl;
    cout << sum (cube,a)<< endl;

    system("PAUSE");
    return 0;
}
