#include<iostream>
using namespace std;
void merge(int *a, int s, int e){
	int temp[100];
	int mid=(s+e)/2;
	int i=s;
	int j=mid;
	int k= s;
	
	while(i<=mid && j<=e){
		if(a[i]<a[j]){
			temp[k++]=a[i++];
		}
		else {
			temp[k++]=a[j++];		}
		}
		while(i<=mid){
			temp[k++]=a[i++];
		}
		while(j<=e){
			temp[k++]=a[j++];
		}
		for(int i=s;i<=e;i++){
			a[i]=temp[i];
		}
		}


void mergeSort(int a[], int s, int e){
	//Base Case
	if(s>=e){
		return;
	}
	//Rec Case
	//1. Devide 
    int mid= (s+e)/2;
    mergeSort(a,s,mid);
    mergeSort(a,mid+1,e);
    merge(a,s,e);

}

int main()
{
	int n;cin>>n;
	int a[1000];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	mergeSort(a,0,n-1);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}