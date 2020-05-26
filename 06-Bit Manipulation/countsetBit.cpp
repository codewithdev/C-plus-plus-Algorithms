#include<iostream>
using namespace std;
int countSetBit(int n){
	int ans=0;
	while(n>0){
      n= n&(n-1);
      ans++;
	}
	return ans;
}
 int main()
 {
 	int n=13;
 	cout<<countSetBit(n);
 	cout<<endl;
 	cout<<__builtin_popcount(n)<<endl;

 }