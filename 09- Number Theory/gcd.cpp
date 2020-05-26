#include<iostream>
using namespace std;
int gcdofnumber(int a, int b){
	return b==0?a:gcdofnumber(b,a%b);
}
int main()
{
	int a,b;cin>>a>>b;
	cout<<gcdofnumber(a,b);
}