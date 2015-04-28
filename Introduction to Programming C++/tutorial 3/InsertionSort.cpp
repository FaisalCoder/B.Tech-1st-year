#include <iostream>
#include<vector>
using namespace std;

void Insert( int b[],int size, int element)
{
    int j=0;
    while( j<size && element>b[j] )
    {
        j++;
    }

    if( j<(size-1))
    {
        for( int y=size-1;y>=j;y--)
        {
            b[y] = b[y-1];
        }

        b[j] = element;
    }

    else
    {
        b[j] = element;
    }
}

void Is(int b[],int size)
{
    if( size == 1)
    Insert(b,2,b[1]);

    else
    {
        Is(b,size-1);
        Insert(b,size,b[size-1]);
    }
}



int main()
{
    int a[]={921,22233,43,8434,8,1,-1};

    Is(a,7);
    for(int i=0; i<7; i++)
    cout << a[i] << " ";
    
    system("pause");
    return 0 ;
}
