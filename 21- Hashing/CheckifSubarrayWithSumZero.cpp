#include<bits/stdc++.h>
using namespace std;
bool checkifSubarraySumZero(int *arr, int n){
   unordered_set<int>s;
   int pre=0;
   for(int i=0;i<n;i++){
   	pre+=arr[i];
   	if(pre==0 or s.find(pre)!= s.end()){
   		return true;
   	}
   	s.insert(pre);
   }
   return false; 
}
int main(int argc, char const *argv[]){
    int n;
    cin>>n;
    int *arr= new int[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }
    bool b= checkifSubarraySumZero(arr,n);
    if(b==0){
    	cout<<"No"<<endl;
    }
    else{
    	cout<<"yes"<<"\n";
    }
    return 0;
}