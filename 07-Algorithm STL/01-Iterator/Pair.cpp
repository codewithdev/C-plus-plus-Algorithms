#include<iostream>
#include<utility>
using namespace std;
int main()
{
	pair<int,int>p(10,20), p1(30,40);
	cout<<(p==p1)<<endl;
	cout<<(p!=p1)<<endl;
	cout<<(p>p1)<<endl;
	cout<<(p<p1)<<endl;
}