/* swap tut 4 Q2 */
#include <iostream>
using namespace std;

void swap (int & ,int &);
int main()
{
    int a,b;
    cout << "Enter two integers" << endl;
    cin >> a >> b;
    cout << " a = " << a << " b = " << b << endl;
    swap(a,b);
    cout << " a = " << a << " b = " << b << endl;
    
     
    system("PAUSE");
    return 0;
}
 
void swap ( int &x ,int &y)
{
     int temp = y;
     y = x;
     x = temp;
     cout << " x = " << x << " y = " << y << endl;
}
