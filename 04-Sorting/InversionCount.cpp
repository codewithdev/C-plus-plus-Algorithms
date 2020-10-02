#include<iostream>
using namespace std;
int merge(int *a, int s, int e){
	int mid= (s+e)/2;
	int i=s;
	int j=mid+1;
	int k=s;
	int temp[1000];
	int cnt=0;

	while(i<=mid and j<=e){
		if(a[i]<=a[j]){
			temp[k++]=a[i++];
		}
		else{
			temp[k++]=a[i++];
			cnt+= mid-i+1;
		}
	}
	while(i<=mid){
		temp[k++]= a[i++];
	}
	while(j<=e){
		temp[k++]=a[i++];
	}
	for(int i=s;i<=e;i++){
		a[i]=temp[i];
}
	return cnt;
}
int inversion_count(int *a, int s, int e){
	if(s>=e){
		return 0;
	}
	int mid= (s+e)/2;
	int x= inversion_count(a,s,mid);
	int y= inversion_count(a,mid+1,e);
	int z= merge(a,s,e);
	return x+y+z;
}
int main()
{
	int a[]= {1,3,4,6,8,0};
	int n= sizeof(a)/sizeof(int);
	cout<<inversion_count(a,0,n-1)<<endl;
}