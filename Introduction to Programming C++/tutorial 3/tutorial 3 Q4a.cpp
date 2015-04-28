#include <iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
using namespace std;


int main()
{
    int a[] = {1,2,3,3,2,1,2,3,2,2,2,2,2,1,1,1,1,3,3,3,3,1};
    // int a[] = {1,3,1,1,3,1,3,1,3,3,1,3,1,3};
    int size = sizeof(a)/sizeof(int);
    int i=0,start=0,end=size-1;

    while( i < size && end >0 )
    {
        if ( i == end)
        break;

        if( a[i] == 1)
        {
            swap(a[i],a[start]);
            start++;
            i++;
        }

        else if ( a[i] == 3)
        {
            if( a[end] == 3)   end--;
            swap(a[i],a[end]);
        }

        else
        {
            i++;
        }
    }

    for( int i=0; i<size; i++)
    {
        cout << a[i];
    }

    return 0;
}







