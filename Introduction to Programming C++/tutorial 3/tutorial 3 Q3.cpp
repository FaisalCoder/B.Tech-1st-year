#include <iostream>
#include<algorithm>
#include<stack>
using namespace std;

class ratio
{
    private:
    int num,den;

    public:
    ratio( int n=0,int d = 1): num(n),den(d){}
    friend ostream& operator<<( ostream & , const ratio & );
    friend bool operator==( ratio & , ratio & );
};

ostream& operator<<( ostream & out, const ratio & r)
{
   return out << r.num << "/" << r.den << endl;
}

bool operator==( ratio & r1, ratio & r2 )
{
    if(r1.num == r2.num && r1.den == r2.den)  return true;
    return false;
}

using namespace std;
int main()
{
    ratio a(2,3), b(2,32);
    cout << a << endl;
    bool c = a==b;
    cout << " = " << c << endl;

    return 0;
}
