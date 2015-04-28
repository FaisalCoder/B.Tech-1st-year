#include<iostream>
#include<new>
using namespace std;

int* found(int[],int,int);

int main()
{
	const int n1=4;
	int a1[n1]={1,2,3,4};
	int m1;
	cout<<"enter no to be found"<<endl;
	cin>>m1;
	cout<<endl;
	int * ans = found(a1,n1,m1);
	//cout<< *ans;
	cout << *ans;
}

int* found(int a[],int n,int m)
{
	int* p = new int;
	for(int i=0;i<n;i++)
	{
		if(a[i]== m)
		{//p=new int;
		*p= a[i];}
		//int l=p;
		//cout << *p << endl;
		return p;

		//else
		//return 0;

	}
}
