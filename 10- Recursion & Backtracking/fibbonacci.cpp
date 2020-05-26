#include<iostream>
using namespace std;
int fib(int n){
	if(n==0 or n==1){
		return n;
	}
	int n1= fib(n-1);
	int n2= fib(n-2);
	int ans= n1+n2;
	return ans;
}


int main()
{
	int n;cin>>n;
	cout<<fib(n);
	return 0;

}