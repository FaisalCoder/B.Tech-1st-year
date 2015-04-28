#include <cmath>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <new>
#include<string>
using namespace std;

string bin( int n)
{
    string d;string ans;
    stringstream ss;
    ans.clear();

    while( n > 0)
    {
        int p = n%2;
        ss << p;
        ss >> d;
        ans += d;
        n = n/2;

        ss.str("");
        ss.clear();
    }
    string a;
    for( int i= ans.length();i>-1;i--)
    {
        a += ans[i];
    }
    string d2 = a.substr(1);

    return d2;
}

bool all1( string s)
{
    for( int i=0; i< s.length(); i++)
    {
        if ( s.find("1") != string::npos )
        {
            int f = s.find("1");
            string d = s.substr(f+1);
            if ( d.find("1") != string::npos )
            {
                int q = d.find("1");

                if( q != 0 )return false;
            }
        }
    }

    return true;
}

inline string sub( string s,const string in)
{
    string ans;
    for( int i=0; i< s.length(); i++)
    {
        if( s[i] == '1' )
        ans += in[i];
    }

    return ans;
}


int main()
{
    int t,i=0;
    cin >> t;
    string in,d;

    while( i < t)
    {
        cin >> in;
        // start
        bool no = false;
        int l = in.length();

        for( int i=1; i< pow(2,l); i++)
        {
            d = bin(i);

            if ( all1(d) == false)
            continue;

            string check = sub(d,in);
            string rev;
            for( int i=check.length();i>-1;i--)
            {
                rev += check[i];
            }


string d1 = rev.substr(1);

            if ( in.find(d1) == string:: npos)
            {
                no = true;
               break;
            }

        }

        if ( no == true)
        cout << "NO" << endl;

        else
        cout << "YES" << endl;

        i++;

    }

    return 0;
}
