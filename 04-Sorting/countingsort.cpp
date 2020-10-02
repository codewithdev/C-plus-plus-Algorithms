#include<iostream>
using namespace std;
void countingsort(int *a, int n){
	int largest= -1;
	for(int i=0;i<n;i++){
		largest= max(largest,a[i]);
	}
	int *freq= new int[largest]{0};
	for(int i=0;i<n;i++){
		freq[a[i]]++;
	}
	int j=0;
	for(int i=0;i<n;i++){
		a[j]=i;
		freq[i]--;
		j++;
	}
}	

int  main()
{
	int a[]= {2,3,5,12,19,6,8};
	int n= sizeof(a)/sizeof(int);
	countingsort(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}
