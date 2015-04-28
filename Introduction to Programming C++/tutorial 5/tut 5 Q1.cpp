#include <iostream>
#define PI 3.14
#define area_circle(x)(PI*(x)*(x))
 
using namespace std;
int main()

{
    int a;
    cout << "Enter radius of circle ";
    cin >> a;
    cout << "Area of circle = " << area_circle(a)<<endl;
    #undef PI 
    #define PI 3.14153
   
    cout << "Area of circle = " << area_circle(a)<<endl;
    
    system("PAUSE");
    return 0;
}
