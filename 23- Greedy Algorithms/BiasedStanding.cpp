/*Spoj Problem :

https://www.spoj.com/problems/BAISED/*/


#include<iostream>
#include<cstring>
using namespace std;
int abs(int i, int j){
	if(i-j>0){
		return i-j;
	}
		return j-i;
	}
int main()
{
	int arr[100000]= {0};
	int t,n;
	cin>>t;
	while(t--){
		memset(arr,0,sizeof arr);
		string name;
		cin>>n;
		int rank;
		for(int i=0;i<n;i++){
             cin>>name>>rank;
		     arr[rank]++;
		}
		int actual_rank=1;
		int sum=0;
		for(int i=1;i<=n;i++){
			while(arr[i]){
				sum+=abs(actual_rank-i);
				arr[i]--;
				actual_rank++;
			}
		}
		cout<<sum<<endl;
	}
}