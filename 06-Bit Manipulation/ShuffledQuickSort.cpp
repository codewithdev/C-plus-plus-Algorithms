#include<iostream>
using namespace std;
void quickSort(int *a, int s, int e){
	if(s>=e){
		return;
	}
	int p= partition(a,s,e);
	quickSort(a,s,p-1);
	quickSort(a,p+1,e);
}
void partition(int *a, int s, int e){
	int i=s-1;
	int j=s;
	int pivot= a[e];
	for(;j<e;j++){
		if(a[j]<=pivot){
			i++;
			swap(a[i],a[j]);
		}
		swap(a[i+1],a[e]);
	}
}

















int  main(){
	int a[]= {2,1,5,6,7,8,9};
	int n= sizeof(a)/sizeof(int);

}