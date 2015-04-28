#include<iostream>
#include<windows.h>
using namespace std;

int main()
{
    enum day{sun,mon,tue,wed,thu,fri,sat};
    day today = sun;

    if ( today == 0)
    cout << "sun";
    sleep(100);

    return 0;
}
