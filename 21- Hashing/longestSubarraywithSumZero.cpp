#include<bits/stdc++.h>
using namespace std;
int checkIfSubarraySumZero(int *arr, int n){
	unordered_map<int,int>mp;
    int pre=0;
    int len=0;
    for(int i=0;i<n;i++){
    	pre+= arr[i];
    	if(arr[i]==0 and len==0){
    		len=1;
    	}
    	if(pre=0){
    		len= max(len,i+1);
    	}
    	if(mp.find(pre)!=mp.end()){
    		len= max(len,i-mp[pre]);
    	}
    	else{
    		mp[pre]=i;
    	}
    }
    return len;
}

int main(){

	int n;
	cin>>n;
	int *arr= new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int b= checkIfSubarraySumZero(arr,n);
	cout<<b<<endl;
	return 0;

}