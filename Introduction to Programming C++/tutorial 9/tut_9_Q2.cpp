#include<iostream>
using namespace std;
 
class one_d
{
    private: 
        int x;
    public :
        void set_coord(int);
        virtual void display_coord();
        one_d (int = 0); 
};

class two_d : public one_d
{
    private:
        int y;
    public :
        virtual void display_coord();
        void set_coord(int);
        two_d (int =0 , int =0 );
};

class three_d : public two_d
{
    private:
        int z;
    public :
        virtual void display_coord();
        void set_coord(int);
        three_d (int =0 ,int =0 ,int =0 );
};

void one_d :: display_coord()
{
    cout << x << endl;
}

void two_d :: display_coord()
{   
    one_d :: display_coord();
    cout << y << endl;
}

void three_d :: display_coord()
{   
    two_d :: display_coord();
    cout << z << endl;
}

void one_d :: set_coord(int value)
{
    x = value;
}
void two_d :: set_coord(int value)
{
    y = value;
}
void three_d :: set_coord(int value)
{
    z = value;
}
    
one_d::one_d (int valuex)
{
             x = valuex;
}

two_d::two_d(int valuex , int valuey)
:one_d(valuex)                  // member wise inintialiser list
{                
             y = valuey;
}

three_d::three_d(int valuex,int valuey,int valuez)
: two_d(valuex,valuey),z(valuez)   //NO NEED OF SEMICOLON AT END(;) OF THIS LINE
{
}// EMPTY BODY OF CONSTRUCTOR 
        
        
int main()
{
    one_d one;
    two_d two;
    three_d three;
    one.set_coord(11);
    two.set_coord(22);
    two.one_d::set_coord(21);
    three.set_coord(33);
    three.two_d::set_coord(32);
    three.one_d::set_coord(31);
    
    one_d * ptr = &one;
    ptr->display_coord();
    
    ptr = &two;
    ptr->display_coord();
    
    ptr = &three;
    ptr->display_coord();
    
    //USING CONSTRUCTOR
    // constructor of base class can be called ONLY in member initialiser list
    // OF derived class.
    three_d test(3);
    test.display_coord();
    
    system("pause");
    return 0;
}
