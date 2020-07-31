#include<iostream>
using namespace std;
//Bottom Up Approach

int fibBU(int n,int dp[]){
	dp[1]=1;
	for(int i=2;i<=n;i++){
		dp[i]= dp[i-1]+dp[i-2];
	}
	return dp[n];
}
int main()
{
	int n;
	cin>>n;
	int dp[100]={0};
	cout<<fibBU(n,dp)<<endl;

}