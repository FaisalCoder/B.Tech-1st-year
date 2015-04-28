/* program to find square or cube tutorial 4 Q3 */
#include <iostream>
#define square 2
#define cube 3
using namespace std;

int square_cube ( int x , int sqcu)
{     
      if ( sqcu == 2 )
      cout << x*x << endl;
      
      if ( sqcu == 3 )
      cout << x*x*x << endl;
}


int main()
{      
       square_cube (4.2,square);
       system ("PAUSE");
       return 0 ; 
}
