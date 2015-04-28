/* program of euclidean algorithm to find greatest common divisor of two numbers
tutorial 3 Q12*/
#include<iostream>
#include<algorithm>
int FindSortedArrayRotation(int A[], int N) {
    int L = 0;
    int R = N - 1;

    while (A[L] > A[R]) {
        int M = L + (R - L) / 2;
        if (A[M] > A[R])
            L = M + 1;
        else
            R = M;
    }
    return L;
}

using namespace std;
int main()
{
    int a[]={5,6,0,1,2,3,4};
    cout << FindSortedArrayRotation(a,7);


    return 0;
}

