// TUTORIAL 7 Q2 AND Q9
#include <iostream>
using namespace std;

int* find(int a[],int n,int SIZE)
{
    int* p = &n;
    for(int i=0; i< SIZE; i++)
    {if( *p == *(a+i))
     return p;
     
     else if( i == (SIZE-1))
     return NULL;}
}


int main()
{
    int a[]= {1,2,33,5,6},n;
    cout << "Enter number to be found ";
    cin >> n;
    cout << find(a,n,5);
    system("PAUSE");
    return 0;
}
        
        
        
        
        
        
        
        
        
        
        
        
        
