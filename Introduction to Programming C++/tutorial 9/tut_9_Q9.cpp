#include<iostream>
#include<fstream>
#include<ctime>
#include<vector>
using namespace std;

struct process
{
    string name;
    float startTime,totalTime;
    string type;
};

/*
int main()
{
    ifstream in;
    in.open("Reader_Writer_Semaphore_input.txt");

   // process p;
    string c,c1;
    int n1,n2;

    //while( in.eof() != true)
    {/*
        in >> p.name ;
        in >> p.type;
        in >> p.startTime;
        in >> p.totalTime;
        cout << p.name;


    }
//       getline(in,c);
       in >> c;
       in >> c1;
       in >> n1;
       in >> n2;

       cout << c << "  " << c1 << "  " << n1 << "  " << n2;




//    system("pause");
    return 0;
    */
    int main()
{
    ifstream in;
    in.open("Reader_Writer_Semaphore_input.txt");


    process p;


    while( in.eof() != true)
    {
        in >> p.name ;
        in >> p.type;
        in >> p.startTime;
        in >> p.totalTime;

        cout << p.name <<  " " << "  " <<  p.type << "  " << p.startTime << " " << p.totalTime << endl;

       // input.push_back(p);
    }

    clock_t mainClock = clock(), temp;
    float current ;
    //start
  /*  while( input.empty() != 0 )
    {
        temp = clock();
        current = float(temp - mainClock)/CLOCKS_PER_SEC;

        for( int i=0; i<input.size(); i++)
        {
            //already waiting processes
            if ( input[i].startTime <= current)
            {
                if ( input[i].type == "Read")
                {
                    process temp = input[i];
                    input.erase(input.begin());
                    reader(temp);

                }

                else
                {
                    process temp = input[i];
                    input.erase(input.begin());
                    writer(temp);   //pop since will always be the first in vector
                }
            }

            temp = clock();
            current = float(temp - mainClock)/CLOCKS_PER_SEC;
        }
    }
*/
    cout << "All process completed" << endl;


    return 0;
}


