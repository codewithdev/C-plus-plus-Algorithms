#include<iostream>
using namespace std;
int dnfsort(int a[], int n){
	int low= 0;
	int high= n-1;
	int mid=0;
	while(mid<=high){
		if(a[mid]==0){
			swap(a[mid],a[low]);
			mid++;
			low++;
		}
		if(a[mid]==1){
			mid++;
		}
		if(a[mid]==2){
			swap(a[mid],a[high]);
			high--;
		}
	}
	return 0;
}

int main()
{
	int a[]= {1,0,0,2,1,1,0,0,1};
	int n= sizeof(a)/sizeof(int);
	dnfsort(a,n);
    for(int i=0;i<n;i++){
    	cout<<a[i]<<" ";
    }
}
