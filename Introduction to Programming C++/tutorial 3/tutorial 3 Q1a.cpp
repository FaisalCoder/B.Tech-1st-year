#include<iostream>
using namespace std;
int* found(int[],int,int);
int main()
{
	const int n=4;
	int a[n]={1,2,3,4};
	//cin>>n;
//	for(int i=0;i<n;i++)
	//{cin>>a[i];
//	}
	int m;
	cout<<"enter no to be found"<<endl;
	cin>>m;
	cout<<endl;
	cout<<*found(a,n,m);
}
int* found(int a[],int n,int m)
{
	int*p;
	for(int i=0;i<n;i++)
	{
		if(a[i]==m)
		{p=new int;
		*p=a[i];
		//int l=p;
		return p;}

		//else
		//return 0;

	}
}
