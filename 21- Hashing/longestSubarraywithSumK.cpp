#include<bits/stdc++.h>
using namespace std;
int checkIfSubarraySumZero(int *arr, int n,int k){
	unordered_map<int,int>mp;
    int pre=0;
    int len=0;
    for(int i=0;i<n;i++){
    	pre+= arr[i];
    	if(pre==k){
    		len= max(len,i+1);
    	}
    	if(mp.find(pre-k)!=mp.end()){
    		len= max(len,i-mp[pre-k]);
    	}
    	else{
    		mp[pre-k]=i;
    	}
    }
    return len;
}

int main(){

	int n;
	cin>>n;
	int k;
	cin>>k;
	int *arr= new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int b= checkIfSubarraySumZero(arr,n,k);
	cout<<b<<endl;
	return 0;

}