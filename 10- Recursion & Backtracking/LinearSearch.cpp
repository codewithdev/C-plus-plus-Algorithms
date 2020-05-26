#include<iostream>
using namespace std;
int linearSearch(int *a, int i, int key, int n){
	if(i==n){
		return -1;
	}
	if(i==key){
		return i;
	}
	return linearSearch(a, i+1, key,n);
}
int main()
{
	int a[]= {1,2,3,5,4,8};
	int n= sizeof(a)/sizeof(int);
	int key;cin>>key;
	cout<<linearSearch(a,0,key,n);
}