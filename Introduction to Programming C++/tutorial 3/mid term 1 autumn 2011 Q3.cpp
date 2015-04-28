#include <iostream>
using namespace std;
int main()
{
    char b;
    int total_count = 0, odd_count = 0, i, a, k = 1;
    while(1)
    {
            cout << "Enter an integer " << endl;
            cin >> a;
            total_count += 1;
            if (a == 0) break;
            else if ((a%2)!= 0)
            {odd_count += 1;
            b += 1 = a;}
    }
    cout << b + 1 ;    
    cout << "Total values entered = " << total_count << endl;
    cout << "Total odd values entered = " << odd_count << endl;   
    system("PAUSE");
    return 0;
}
