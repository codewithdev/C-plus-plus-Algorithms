#include<iostream>
using namespace std;
int main()
{
	int cs=0;
	int ms=0;
	int n;cin>>n;
	int a[100];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		
	}
	for(int i=0;i<n;i++)
	{
		cs= cs+a[i];
		if(cs<0)
		{
			cs=0;
		}
		ms= max(ms,cs);
	}
	cout<<"MAXIMUM SUM IS:"<<ms<<endl;
}
