//tut 7 Q12
#include<iostream>
#include<new>
using namespace std;

int main()
{
    int size;
    cout << "Enter size of array = ";
    cin >> size;
    
    int* ptr= new int [size];
    
    for(int i=0; i<size ; i++)
    *(ptr + i) = 0;
    
    for(int i=0; i<size ; i++)
    cout << ptr[i] << endl;         // can also use *(ptr + i)
    
    delete []ptr;
    
    system("PAUSE");
    return 0;
}
