#include<iostream>
using namespace std;
void readmatrix(int a[][10],int R,int C)
{
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			cin>>a[i][j];
		}
	}
	
}
void printmatrix(int a[][10],int R,int C)
{
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			cout<<a[i][j]<<" ";
		}
	cout<<endl;
	}
	
}
int main()
{
	int R,C;cin>>C>>R;
	int a[10][10];
	readmatrix(a,R,C);
	printmatrix(a,R,C);
}