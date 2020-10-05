/*
* Merge sort algorithm works on divide and conquer concept
* This code shows divide and conquer steps in two different functions separately
*/
#include<iostream>
#include<vector>
using namespace std;

void merging(vector<int> &ar,int low,int mid,int high){
	int I=low,J=mid+1,K=0,br[10000];
	while(I<=mid && J<=high) br[K++] = ar[I]<=ar[J] ? ar[I++] : ar[J++];
	while(I<=mid) br[K++]=ar[I++];
	while(J<=high) br[K++]=ar[J++];
	while(--K>=0) ar[low+K]=br[K];
}

void merg_sort(vector<int> &ar,int low,int high){
	if(low<high){
		int mid = (low+high)/2;
		merg_sort(ar,low,mid);
		merg_sort(ar,mid+1,high);
		merging(ar,low,mid,high);
	}
}

int main(){
	int n;
	cin >> n;
	vector<int> ar(n);
	for(int I=0;I<n;I++) cin >> ar[I];

	merg_sort(ar,0,n-1);
	for(int I=0;I<n;I++) cout << ar[I] << " ";
	return 0;
}
