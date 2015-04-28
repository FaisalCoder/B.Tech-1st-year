/* program that prints factorial  of a given number using do-while loop */
#include <iostream>
using namespace std;
int main()
{
    int n ,i=1, fact = 1;
    cout << "Enter a number " ;
    cin >> n;
    if (n == 0)
    cout << "Factorial (0) = 1" << endl;
    else if (n > 0)
    {
         do
        { fact *=i;
         i++;}
         while (i <= n );
         cout << fact;
         }
         else if (n < 0 )
    cout << "INVALID ENTRY!!! ENTER A POSITIVE NUMBER" << endl;
    system("PAUSE");
    return 0;
}
         
