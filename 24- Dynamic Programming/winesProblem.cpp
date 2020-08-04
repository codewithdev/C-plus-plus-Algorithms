/*We have given prices of wine, we need to sell wines so that we can make maximum profit from it.
1) Each year the price of the wine increases.
2) Select the wine bottle from either one end or other so that we can make maximum profit throughout
   the year.

Example :


wines P= [2,3,5,1,4]


*/


#include<iostream>
using namespace std;
int profit(int wines[], int i, int j, int y, int dp[][100]){

	//Base case
	if(i>j){
		return 0;
	}
	//Return if dp[i][j]

	if(dp[i][j]!=0){
		return dp[i][j];
	}
	int op1= wines[i]*y+profit(wines, i+1,j,y+1,dp);
	int op2= wines[j]*y+profit(wines, i, j-1, y+1,dp);
	return dp[i][j]= max(op1, op2);
}
int main(){
	int wines[]= {2,3,5,1,4};
	int dp[100][100]={0};
	int n= sizeof(wines)/sizeof(int);
    int y=1;
    cout<<profit(wines, 0,n-1,y,dp);
	return 0;
}