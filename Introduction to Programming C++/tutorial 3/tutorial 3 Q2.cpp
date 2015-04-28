#include <iostream>
#include <map>
#include<vector>
#include<sstream>
#include<string>
#include<new>
#include<fstream>
using namespace std;

bool search( vector<string> m,string other)
{
    for( int i=0; i< m.size(); i++)
    {
        if( other == m[i])
        return true;
    }

    return false;
}

int search2( vector<string> m,string other)
{
    for( int i=0; i< m.size(); i++)
    {
        if( other == m[i])
        return i;
    }

    return -1;
}


int main()
{
    ifstream in;
    in.open("fb.txt");
    string first,s,dummy;
    getline(in,first);
    cout << first << endl;

    stringstream ss ;
    ss << first;

    //make array of the string
    vector<string> main;
    vector<string>::iterator ite;


    while( ss >> dummy)
    {
        main.push_back(dummy);
    }

    int size1 = main.size();
    cout << size1;

    for( int i=0; i<size1; i++)
    cout << main[i] << endl;

    ss.str("");
    ss.clear();

    while( !in.eof())
    {
        getline(in,s);
        ss << s;
        int i=0;

        map<int,string> temp;
         map<int,string>::iterator it,it2,it3;
        while( ss >> s )
        {

            if( search(main,s))
            {
                //found
                temp[i] = s;
            }

            i++;

        }
        ss.str("");
            ss.clear();

        int count=0;
        for(int j=0; j<temp.size()-size1;j++)
        {
            it2 = temp.begin();
            for( int p=0;p<j;p++)
            it2++;
            it = it2;

            for( int p=0;p<size1;p++)
            it2++;

            for(  ;it != it2; it++)
            {
                it3 = it++;
                it--;

                if (it->first - it3->first != -1)
                break;

                int l;
                if((l= search2(main,it->second)) != -1)
                main.erase(main.begin()+l);

            }

            if( main.empty() == true)
            count++;

            main.clear();
            ss << first;
            while( ss >> dummy)
            {
                main.push_back(dummy);
            }
            ss.str("");
            ss.clear();
        }

        cout << "COUNT IS" << count << endl;

        //rest
            temp.clear();
            ss.str("");
            ss.clear();



    }

    return 0;
}

