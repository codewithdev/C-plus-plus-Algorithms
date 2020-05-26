#include<iostream>
using namespace std;
void clearRangeBit(int &n, int i, int j){
	int a= -1<<(j+1);
	int b= (1<<i)-1;
	int mask= a|b;
	n= n&mask;
}
 int main()
 {
 	int n=155;
 	int i;cin>>i;
 	int j;cin>>j;
 	clearRangeBit(n,i,j);
 	cout<<n;
 }
