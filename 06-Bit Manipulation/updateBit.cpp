#include<iostream>
using namespace std;
void updateBit(int &n,int v, int i){
	int clearBit= ~(1<<i);
	int mask= n & clearBit;
	n= mask |(v<<i);
}
int main()
{
	int n=25;
	int v;cin>>v;
	int i;cin>>i;
	updateBit(n,v,i);
	cout<<n;
}