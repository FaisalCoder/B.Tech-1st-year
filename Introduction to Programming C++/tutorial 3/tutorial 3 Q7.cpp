/* program to check whether given sides represent sides of a triangle
tutorial 3 Q7 */
#include <iostream>
using namespace std;

int* f(int * a)
{
    return a;
}

int main()
{
    int b = 10;
    int* c = &b;
    int * d = f(c);
    cout << *d << endl;

    return 0;
}
