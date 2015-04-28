#include<iostream>
using namespace std;

class marks
{
      int x,y;

      public:
             marks(int obt,int tot):x(obt), y(tot){}
             marks():x(0), y(0){}
             marks(const marks & mymarks){ x = mymarks.x; y = mymarks.y;}
             friend marks operator+(marks,marks);
             friend marks operator+(marks,int);
             friend bool operator>(marks,marks);
             friend ostream& operator<<(ostream&,marks);
             void changescore (int a){ x = a;}
             void operator= (marks a){ x = a.x; y= a.y;}

};

marks operator+(marks a,marks b)
{
      marks c;
      c.x = a.x + b.x;
      c.y = a.y + b.y;
      return c;
}

marks operator+(marks a,int b)
{
      a.x += b;
      return a;
}

ostream& operator<<(ostream& output,marks a)
{
         output << "Score is " << a.x << " out of " << a.y << endl;
}

bool operator>(marks a, marks b)
{
     if( a.x/a.y > b.x/b.y )
     return true;
     else
     return false;
}

class b
{
    marks w;
    w
};

int main()
{
    marks faisal(95,100),sahil,khan(3,100),ramesh;
    cout << faisal << sahil;
    sahil = faisal;
    cout << sahil;
    sahil = faisal + khan;
    cout << sahil;
    ramesh = faisal + -26;
    cout << ramesh;
    ramesh.changescore(100);
    cout << ramesh;
    cout << (khan>faisal);

   // system("pause");
    return 0;
}



