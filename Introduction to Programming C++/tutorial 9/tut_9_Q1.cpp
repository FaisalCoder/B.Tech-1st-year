#include<iostream>
#include<ctime>
#include<list>
using namespace std;

class process;
struct semaphore
{
    public:
    //semaphore(){value=0;};
    int value;
    list<process> waiting;
};


class process
{
    public :
    process(){name="";time=0;}
    string name;
    float time;
    static semaphore wrt,mutex;
    static int readcount;
   //  friend class semaphore;


 static int wait ( semaphore s , process p , string todo)
{
    s.value--;

    if ( todo == "exe_p" && s.value < 0)
    {
        cout << "Process will be executed after some time" << endl;
        process temp;
        temp.name = p.name;
        temp.time = p.time;
        (s.waiting).push_back(temp);
        return -1;
    }
    return 0;
}

static void signal ( semaphore s)
{
    s.value++;
    if ( s.value <= 0 )
    {
        process temp = (s.waiting).front();

        //activate this temp process by calling the process either read or write
        if ( (s.waiting).empty() != 0 )
        {
            (s.waiting).pop_front();

            if ( temp.name == "read")
            reader(wrt,mutex,temp);

            else
            writer(wrt,temp);
        }
    }
}


//Readers-Writers Problem
static void writer( semaphore wrt , process p )
{
    if ( wait(wrt,p,"exe_p") == -1) return;
    // Writing is done
    clock_t t1,t2;
    t1 = clock();
    t2 = t1;
    cout << "Please wait for write to complete..." << endl;
    do
    {
        t1 = t2;
        t1 = clock() - t1;

        //do
        int choice;
       {
        cout << "Enter 1 to execute a read process" << endl;
        cout << "Enter 2 to execute a write process" << endl;
        cout << "Enter 3 to exit" << endl;
        cout << "CHOICE : ";
        cin >> choice;
        process start;

        switch( choice )
        {

            case 1:
            cout << "Enter time taken to execute" ;
            cin >> start.time;
            start.name = "read";
            process::reader(wrt, mutex ,start);
            break;

            case 2:
            cout << "Enter time taken to execute" ;
            cin >> start.time;
            start.name = "write";
            process::writer(wrt,start);
            break;

            case 3:
            break;

            default:
            cout << "Enter right choice" << endl;
            break;
        }

        if ( float(t1)/CLOCKS_PER_SEC == p.time)
        break;

    }while( choice != 3 );
    //



    }while( float(t1)/CLOCKS_PER_SEC != p.time);

    cout << "Write complete" << endl;
    signal(wrt);
}

static void reader(semaphore wrt , semaphore mutex , process p)
{
    //blocking mutex while updating readcount
    if ( wait(mutex,p,"exe_p") == -1) return; // mutex already taken

    readcount++;

    if (readcount == 1)
        wait(wrt,p,"no_exe");
    signal(mutex);

    // Do the Reading
    clock_t t1,t2;
    t1 = clock();
    t2 = t1;
    cout << "Please wait for read to complete..." << endl;
    do
    {
        t1 = t2;
        t1 = clock() - t1;

        //
          int choice;
        do
    {
        cout << "Enter 1 to execute a read process" << endl;
        cout << "Enter 2 to execute a write process" << endl;
        cout << "Enter 3 to exit" << endl;
        cout << "CHOICE : ";
        cin >> choice;
        process start;

        switch( choice )
        {

            case 1:
            cout << "Enter time taken to execute" ;
            cin >> start.time;
            start.name = "read";
            process::reader(wrt, mutex ,start);
            break;

            case 2:
            cout << "Enter time taken to execute" ;
            cin >> start.time;
            start.name = "write";
            process::writer(wrt,start);
            break;

            case 3:
            break;

            default:
            cout << "Enter right choice" << endl;
            break;
        }

        if ( float(t1)/CLOCKS_PER_SEC == p.time)
        break;

    }while( choice != 3 );
    //


    }while( float(t1)/CLOCKS_PER_SEC != p.time);

    cout << "Read complete" << endl;
    // (Critical Section Area)
    wait(mutex,p,"no_exe");
    readcount--;

    if (readcount == 0)
        signal(wrt);
    signal(mutex);
}
};

semaphore process::mutex ;
  semaphore  process ::wrt;
  int  process::readcount ;

int main()
{
    semaphore wrt, mutex;
    wrt.value=1, mutex.value=1;
    int readcount=0,choice;
    float tim;
    process::mutex = mutex;
    process ::wrt = wrt;
    process::readcount = readcount;

    do
    {
        cout << "Enter 1 to execute a read process" << endl;
        cout << "Enter 2 to execute a write process" << endl;
        cout << "Enter 3 to exit" << endl;
        cout << "CHOICE : ";
        cin >> choice;
        process start;

        switch( choice )
        {

            case 1:
            cout << "Enter time taken to execute" ;
            cin >> start.time;
            start.name = "read";
            process::reader(wrt, mutex ,start);
            break;

            case 2:
            cout << "Enter time taken to execute" ;
            cin >> start.time;
            start.name = "write";
            process::writer(wrt,start);
            break;

            case 3:
            break;

            default:
            cout << "Enter right choice" << endl;
            break;
        }

    }while( choice != 3 );


    return 0;
}
