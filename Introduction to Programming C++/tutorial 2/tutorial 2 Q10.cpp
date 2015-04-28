#include<iostream>
#include<ctime>
#include<string>
using namespace std;

int main()
{
    clock_t t,temp;
    float t3 = 4;
    t = clock();
    temp = t;
    cout << float(temp)/CLOCKS_PER_SEC ;
    string s;
    int count=0,i=0;
    float timer = 0;

    do
    {
        t = temp;
        t = clock() - t;

        if ( count == 0 )
        {
            cout << "Enter " ;
            cin >> s;
        }

    /*     if ( float(t)/CLOCKS_PER_SEC == timer)
        cout << s[timer++] << endl;

*/
        if ( float(t)/CLOCKS_PER_SEC == t3)
        {
            cout << "yes" << " " << s << endl;
        break;
        }

        count++;

    }while( float(t)/CLOCKS_PER_SEC < t3);

    cout << float(clock())/CLOCKS_PER_SEC  << endl;
    cout << "done" ;


    return 0;
}
