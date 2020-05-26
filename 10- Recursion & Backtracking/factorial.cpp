#include<iostream>
using namespace std;
int fact(int num){
	if(num==0){
		return 1;	
	}
	int ans= num*fact(num-1);
	return ans;
}
int main(){
	int n;cin>>n;
	cout<<fact(n);
}