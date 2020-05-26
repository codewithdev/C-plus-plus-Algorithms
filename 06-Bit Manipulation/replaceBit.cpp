#include<iostream>
using namespace std;
int clearBit(int n, int i, int j){
	int a= -1<<(j+1);
	int b= (1<<i)-1;
	int mask= a|b;
	int ans= n &mask;
	return ans;
}
int replaceBit(int n, int M, int i, int j){
 int n_c= clearBit(n,i,j);
 int ans = n_c |(M<<i);
 return ans;
}
int main()
{
	int n= 131;
	int i;cin>>i;
	int j;cin>>j;
	int M;cin>>M;
	cout<<replaceBit(n,M,i,j)<<endl;
}