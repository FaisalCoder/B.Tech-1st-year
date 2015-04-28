#include<iostream>
#include<new>
#include<vector>
using namespace std;

//safety alogorithm
bool safety_check(int** need,int** allocation, int * available,int no_process, int no_resources)
{

    cout << "SEE THIS" << endl;

    //output all 3 matrix
     //allocation
     cout << "Allocation matrix"  << endl;
     for( int i=0; i<no_resources; i++)
     {
         cout << "  R" << i << " ";
     }
     cout << endl;

     for( int i=0;i<no_process;i++)
     {
         cout << "P" << i << " ";
         for( int j=0;j<no_resources;j++)
         {
             cout << allocation[i][j] << "   ";
         }
         cout << endl;
     }

  /*   cout << "Max matrix"  << endl;
     for( int i=0; i<no_resources; i++)
     {
         cout << "  R" << i << " ";
     }
     cout << endl;

     for( int i=0;i<no_process;i++)
     {
         cout << "P" << i << " ";
         for( int j=0;j<no_resources;j++)
         {
             cout << max[i][j] << "   ";
         }
         cout << endl;
     }
*/
     cout << "Available matrix"  << endl;
     for( int i=0; i<no_resources; i++)
     {
         cout << "  R" << i << " ";
     }
     cout << endl;
     cout << "  ";
     for( int j=0;j<no_resources;j++)
         {
             cout << available[j] << "   ";
         }
         cout << endl;

     cout << "Need matrix"  << endl;
     for( int i=0; i<no_resources; i++)
     {
         cout << "  R" << i << " ";
     }
     cout << endl;

     for( int i=0;i<no_process;i++)
     {
         cout << "P" << i << " ";
         for( int j=0;j<no_resources;j++)
         {
             cout << need[i][j] << "   ";
         }
         cout << endl;
     }
//ends

    int * work = new int[no_resources];
    for( int i=0;i<no_resources;i++)
    {
        work[i] = available[i];
    }

    bool * finish = new bool[no_process];
    for( int i=0; i<no_process; i++)
    {
        finish[i] = false;
    }

    bool notsafe = false,fail = false;
   int total_finish = 0;

        int i3=0;
        for( ; i3<no_process; i3++)
        {
            notsafe = false;
            if ( finish[i3] == false )
            {cout << "Entering process " << i3 << endl;
                for( int k=0;k<no_resources;k++)
                {

                   if( need[i3][k] > work[k] )
                   notsafe = true;
                }

                if( notsafe == false)
                {
                    cout << "process " << i3 << endl;
                    for( int i2=0; i2<no_resources; i2++)
                    {
                        work[i2] += allocation[i3][i2];
                    }

                    cout << endl;
                    cout << "Work " << endl;
                    for( int i2=0; i2<no_resources; i2++)
                    {
                        cout << work[i2] << " ";
                    }

                    finish[i3] = true;
                    total_finish++;
                    i3=0;
                }
            }
        }

       /* bool pass = true;
        for( int i=0;  i<no_process; i++)
        {
            if ( finish[i] == false)
            pass = false;
        }*/

        if ( total_finish == no_process)
        return true;
        return false;

       // return pass;
}

//resource request algorithm
bool resource_request(int **need, int** allocation,int *available,int no_process,int no_resources,int process)
{
    cout << "Enter the Requested resources" << endl;
    int * request = new int[no_resources];

    cout << "Enter the number of Requested resources for Process " << process << endl;
    for( int i=0; i<no_resources; i++)
    {
        cout << "Resource " << i << " : ";
        cin >> request[i];
    }

    //validating
    for( int i=0; i<no_resources;i++)
    {
        if( request[i] > need[process][i])
        {
            cout << "Error!!" << endl;
            return false;
        }
    }

    for( int i=0; i<no_resources;i++)
    {
        if( request[i] > available[i])
        {
            return false;
        }
    }

    //redo if not a safe state
    for( int i=0; i<no_resources;i++)
    {
        available[i] -= request[i];
    }

    for( int i=0; i<no_resources;i++)
    {
        allocation[process][i] += request[i];
    }

    for( int i=0; i<no_resources;i++)
    {
        need[process][i] -= request[i];
    }

    bool ans = safety_check(need,allocation,available,no_process,no_resources);

    if ( ans == false)
    {
        //redo the previous states
        for( int i=0; i<no_resources;i++)
        {
            available[i] += request[i];
        }

    for( int i=0; i<no_resources;i++)
        {
            allocation[process][i] -= request[i];
        }

    for( int i=0; i<no_resources;i++)
        {
            need[process][i] += request[i];
        }

    }

    return ans;
}

int main()
{
    int actual = 0, counter = 0,no_process,no_resources;

    cout << "Enter number of processes : ";
    cin >> no_process;
    cout << "Enter number of resources : ";
    cin >> no_resources;

     int * total = new int[no_resources];

     for( int j=0; j<no_resources; j++ )
     {
         cout << "Enter total number of instances of Resource " << j << " : ";
         cin >> total[j];
     }

    int ** max = new int*[no_process];
    for( int i=0;i<no_process;i++)
    {
        max[i] = new int[no_resources];
    }

    for( int i=0;i<no_process;i++)
    {
        cout << "\t\tEnter maximum number of resources for Process " << i << endl;
        for( int j=0; j<no_resources; j++ )
        {
            cout << "Resource " << j << " : ";
            cin >> max[i][j];
        }
        cout << endl;
    }

    int ** allocation = new int*[no_process];
    for( int i=0;i<no_process;i++)
    {
        allocation[i] = new int[no_resources];
    }

    for( int i=0;i<no_process;i++)
    {
        cout << "\tEnter allocated number of resources for Process " << i << endl;
        for( int j=0; j<no_resources; j++ )
        {
            cout << "Resource " << j << " : ";
            cin >> allocation[i][j];
        }
         cout << endl;
    }

    int ** need = new int*[no_process];
    for( int i=0;i<no_process;i++)
    {
        need[i] = new int[no_resources];
    }

    for( int i=0;i<no_process;i++)
    {
        for( int j=0; j<no_resources; j++ )
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

     int * available = new int[no_resources];
     for( int j=0; j<no_resources; j++ )
     {
         int a_total=0;
         for( int i=0;i<no_process;i++)
         a_total += allocation[i][j];

         available[j] = total[j] - a_total;
     }

     bool result = safety_check(need,allocation,available,no_process,no_resources);

     //output all 3 matrix
     //allocation
     cout << "Allocation matrix"  << endl;
     for( int i=0; i<no_resources; i++)
     {
         cout << "  R" << i << " ";
     }
     cout << endl;

     for( int i=0;i<no_process;i++)
     {
         cout << "P" << i << " ";
         for( int j=0;j<no_resources;j++)
         {
             cout << allocation[i][j] << "   ";
         }
         cout << endl;
     }

     cout << "Max matrix"  << endl;
     for( int i=0; i<no_resources; i++)
     {
         cout << "  R" << i << " ";
     }
     cout << endl;

     for( int i=0;i<no_process;i++)
     {
         cout << "P" << i << " ";
         for( int j=0;j<no_resources;j++)
         {
             cout << max[i][j] << "   ";
         }
         cout << endl;
     }

     cout << "Available matrix"  << endl;
     for( int i=0; i<no_resources; i++)
     {
         cout << "  R" << i << " ";
     }
     cout << endl;
     cout << "  ";
     for( int j=0;j<no_resources;j++)
         {
             cout << available[j] << "   ";
         }
         cout << endl;

     cout << "Need matrix"  << endl;
     for( int i=0; i<no_resources; i++)
     {
         cout << "  R" << i << " ";
     }
     cout << endl;

     for( int i=0;i<no_process;i++)
     {
         cout << "P" << i << " ";
         for( int j=0;j<no_resources;j++)
         {
             cout << need[i][j] << "   ";
         }
         cout << endl;
     }


     if( result == true)
     cout << "Safe state" << endl;

     else
     cout << "Unsafe state" << endl;

     //resource-request algorithm
     int process;
     cout << "Enter process for which resources are requested" << endl;
     cin >> process;
     bool result2 = resource_request(need,allocation,available,no_process,no_resources,process);

     if( result2 == true)
     cout << "Request granted" << endl;

     else
     cout << "Request not granted" << endl;

    return 0;

}
