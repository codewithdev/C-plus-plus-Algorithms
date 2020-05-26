#include<iostream>
using namespace std;
int isArraySorted(int *a, int n){
	if(n==1){
		return true;
	}
	if(a[0]<a[1] and isArraySorted(a[i+1],n-1))
		return true;
}
return false;
int main()
{
	int n;cin>>n;
	int a[1000];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(isArraySorted(){

	cout<<isArraySorted(a,n);
}
