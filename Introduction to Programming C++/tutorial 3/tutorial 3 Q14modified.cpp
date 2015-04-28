#include <iostream>
#include <new>
using namespace std;

struct detail
{
    char city;
    int cost;
};

struct sort_data
{
    int city_index;
    int length;
};

void InsertionSort( sort_data a[], int size)
{
    int k,key;
    sort_data key2;
    for ( int j=1; j<size; j++)
    {
        k = j-1;
        key = a[j].length;
        key2 = a[j];
        while ( k >= 0 && key < a[k].length)
        {
            a[k+1] = a[k];
            k--;
        }
        a[k+1] = key2;
    }
}

int main()
{
    int n,m,i=0;
    cin >> n >> m;
    detail* a = new detail[n];

    while( i < n)
    {
        cin >> a[i].city >> a[i].cost;
        i++;
    }

    i=0;
    int ** b = new int* [n];
    for( int i=0; i<n; i++)
    {
        b[i] = new int[n+1];

        for( int j=0; j<n+1; j++)
        b[i][j] = 0;
    }

    int x,y;
    i=0;
    while( i < m)
    {
        cin >> x >> y;

        if ( a[x-1].city != a[y-1].city)
        {
            b[x-1][y-1] = a[y-1].cost;
            b[x-1][n] += a[y-1].cost;
            b[y-1][x-1] = a[x-1].cost;
            b[y-1][n] += a[x-1].cost;
        }


        i++;
    }

    //sort the array on basis of length
    sort_data * s = new sort_data[n];
    for ( int i=0; i<n; i++)
    {
        s[i].city_index = i;
        s[i].length = b[i][n];
    }

    InsertionSort(s,n);

    int total = 0;
    for ( int i=0; i<n ; i++)
    {
        int index = s[n-i].city_index;
        if ( b[index][n] < a[index].cost )
        {
            total += b[index][n];
            b[index][n] = 0;

            for( int j=0; j<n ; j++)
            {
                b[j][n] -= b[j][index];
                b[j][index] = 0;
            }
        }
    }

    for( int i=0; i<n ; i++)
    {
        int index = s[i].city_index;
        if ( b[index][n] != 0)
        {
            total += a[index].cost;
            for ( int j=0; j<n ; j++)
            {
                b[j][index] = 0;
            }
        }
    }

    cout << total << endl;


    return 0;
}
