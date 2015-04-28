//tut 5 Q9
#include <iostream>
using namespace std;
 


int main()
{
  int a[]={1,4,5,3,13},m=2;
  for(int i=0; i<5;i++)
  {for(int j=0; j<5;j++)
  
   {for(int k=0; k<5;k++)
     { if( a[i]*a[i] + a[j]*a[j] == a[k]*a[k] )
       {cout << a[i] << "  " << a[j] << "  " << a[k] << endl;
        m=0;
        break;}}}
        if(m==0) break;}
       
  system("PAUSE");
  return 0;  
}

