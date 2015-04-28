#include <iostream>
using namespace std;
int main()
{
    int a[]={0,1,0,0,1,0,1,1};
    int size = sizeof(a)/sizeof(int);
    int zero=0,one=0;

    for( int i=0;i<size; i++)
    {
        zero = one = 0;
        for( int j=i; j<size; j++)
        {
            if(a[j]== 0)
            zero++;

            else
            one++;

            if(zero == one)
            cout << "( " << i << " , " << j << " )" << endl;
        }
    }

    return 0;
}
