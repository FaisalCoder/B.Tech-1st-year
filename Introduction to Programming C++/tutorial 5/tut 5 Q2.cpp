#include <iostream>
#ifndef volume_cone
#define volume_cone(r,h)(3.14*(r*r)*h/3)
#endif
using namespace std;
int main()
{
    float r,h ;
    cout << "Enter radius and height of cone " << endl;
    cin >> r >> h;
    cout << "volume of cone = " << volume_cone(r,h) << endl;
    
      system("PAUSE");
    return 0;
}
