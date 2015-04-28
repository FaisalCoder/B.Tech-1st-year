//tut 7 Q6
#include<iostream>
#include<new>
using namespace std;

int main()
{
    int a[2][3]={11,12,13,21,22,23};
    for(int i=0;i<2;i++)
    {for(int j=0;j<3;j++){
    cout << "a[" << i << "][" << j << "] = " << *(a[i]+j) << "\t&a[" 
    << i << "][" << j << "] = " << (a[i]+j) << endl;}}
    
    system("PAUSE");
    return 0;
    
    
  
}
        
