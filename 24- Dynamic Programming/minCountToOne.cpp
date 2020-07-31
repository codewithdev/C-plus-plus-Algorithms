#include<iostream>
#include<climits>
using namespace std;
//Min steps to one
//n->n/3, n->n/2, n->n-1
int countOne(int n, int dp[]){
	int count=0;
	if(n==1){
		return 0;
	}
	if(dp[n]!=0){
		return dp[n];
	}
    int op1, op2, op3;
    op1=op2=op3= INT_MAX;
	if(n%3==0){
     op1= countOne(n/3,dp);
	}
	if(n%2==0){
		op2= countOne(n/2,dp);
	}
	op3= countOne(n-1,dp);
	int ans= min(op1,min(op2,op3))+1;
	return dp[n]=ans;
}
int main(){
	int n;
	cin>>n;
	int dp[100]={0};
	cout<<countOne(n,dp)<<endl;
}