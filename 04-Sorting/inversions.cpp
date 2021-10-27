/*
Count Inversions in an array using both the O(n^2) solution and using the optimised O(nlogn) solution. 
Inversion Count for an array indicates – how far (or close) the array is from being sorted. If the array is already sorted, then the inversion count is 0, but if the array is sorted in the reverse order, the inversion count is the maximum. 
Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j 
*/
#include "bits/stdc++.h"
using namespace std;
void printArr(int arr[], int n,string s="\n"){
	if(s==" "){
		for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;	
	}
	else{
		for(int i=0;i<n;i++){
		cout<<arr[i]<<'\n';
	}
	}
	}
int merge(int left[], int right[], int arr[], int leftLength, int rightLength){
	//the helper function which helps to merge two arrays, left and right
	int i=0,j=0,k = 0;
	int inversions = 0 ;
	while(i< leftLength && j<rightLength){
		if(left[i]<=right[j]){
			arr[k]= left[i];
			i++;
			k++;
		}
		else {
			arr[k] = right[j];
			j++;
			k++;
			inversions += leftLength - i;
		}
	}
	while(i<leftLength){
		arr[k] = left[i];
		i++;
		k++;
		//inversions += rightLength;

	}
	while(j<rightLength){
		arr[k] = right[j];
		j++;
		k++;
	}
	return inversions;
}
int mergeSort(int arr[], int n){
	//the main merge sort function takes in array and the number of elements in the array
	int mid = n/2;
	if(n<2){
		return 0;
	}
	int left[mid];
	int right[n-mid];
	
	for(int i = 0 ; i<mid;i++){
		left[i] = arr[i];
	}
	//printArr(left, mid," ");
	int i = 0 ;
	for(int j = mid;j<n;j++){
		right[i] = arr[j];
		i++;
	}
	//printArr(right, n-mid," ");
	int x = mergeSort(left, mid);
	int y = mergeSort(right, n- mid);
	int z = merge(left, right, arr,mid, n- mid);
	
	return x+y+z;
		
}
int inversions(int arr[], int n){
	int d = 0;
	for(int i = 0 ;i< n;i++){
		for(int j = i+1;j<n;j++){
			if(arr[i]>arr[j]){
				d++;
			}
		}
	}

return d;}
int main(){
	int arr[8] = {2,1,4,6,7,5,3,8};
	cout<< "Inversions are:"<< inversions(arr,8)<<endl;
	cout<< "Inversions output:"<< mergeSort(arr,8)<<endl; 	
	return 0;
}
