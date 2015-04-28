#include<iostream>
#include<ctime>
#include<vector>
#include<fstream>
using namespace std;









//start new logic by creating two queues one input and one for
// for waiting process and output the process along with thand then using wait with less arguments
struct process
{
    string name;
    float startTime,totalTime;
    string type;
};



struct semaphore
{
    int value;
    vector<process> waiting;
    semaphore(int a) : value(a){}
};

void writer( process  );
void reader(process );

semaphore wrt(1), mutex(1) ;
//wrt.value = 1 ; mutex.value = 1;

int readcount=0;
vector<process> input;
ofstream out;







int wait ( semaphore s , process p )
{
    s.value--;

    if ( s.value < 0)
    {
        s.waiting.push_back(p);
        return -1;
    }
           //block the next requesting process
    return 0;
}

void signal ( semaphore s)
{
    s.value++;

    if ( s.value <= 0 )
    {
        process temp = s.waiting[0];

        if ( s.waiting[0].type == "Read" )
        {
            ((s.waiting)).erase((s.waiting).begin());
            reader(temp);
        }

        else
        {
            (s.waiting).erase((s.waiting).begin());
            writer(temp);
        }

    }        // execute waiting process

}


//Readers-Writers Problem
void writer( process p )
{
    if ( wait(wrt,p) == -1 )
    return;

    // Writing is done
    clock_t t1,t2;
    t1 = clock();
    t2 = t1;
    cout << "Please wait for write to complete..." << endl;
    do
    {
        t1 = t2;
        t1 = clock() - t1;

        if ( float(t1)/CLOCKS_PER_SEC == p.totalTime)
        break;

    }while( float(t1)/CLOCKS_PER_SEC != p.totalTime);

  //  cout << "Write complete" << endl;
  string s = "finished " ;
  out << s;
  out << p.name;
  out << p.startTime;
  out << p.totalTime;
  out << p.type;

    signal(wrt);
}

void reader(process p)
{
    //blocking mutex while updating readcount
    if (wait(mutex,p) == -1)
    return;

    readcount++;

    if (readcount == 1)
    {
        if (wait(wrt,p) == -1)
        return;
    }

    signal(mutex);

    // Do the Reading
    clock_t t1,t2;
    t1 = clock();
    t2 = t1;
    cout << "Please wait for write to complete..." << endl;
    do
    {
        t1 = t2;
        t1 = clock() - t1;

        if ( float(t1)/CLOCKS_PER_SEC == p.totalTime)
        break;

    }while( float(t1)/CLOCKS_PER_SEC != p.totalTime);

    // (Critical Section Area)
    if ( wait(mutex,p) == -1 )
    return;
    readcount--;
    string s = "finished " ;
   out << s;
  out << p.name;
  out << p.startTime;
  out << p.totalTime;
  out << p.type;

    if (readcount == 0)
        signal(wrt);
    signal(mutex);
}


int main()
{
    ifstream in;
    in.open("Reader_Writer_Semaphore_input.txt");
    out.open("output.txt");

    process p;


    while(true )
    {

        in >> p.name ;
        in >> p.type;
        in >> p.startTime;
        in >> p.totalTime;

        if(in.eof() == true )break;


        cout << p.name <<  " " << "  " <<  p.type << "  " << p.startTime << " " << p.totalTime << endl;



       // input.push_back(p);
    }

    clock_t mainClock = clock(), temp;
    float current ;
    //start
    while( input.empty() != 0 )
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

    cout << "All process completed" << endl;


    return 0;
}
