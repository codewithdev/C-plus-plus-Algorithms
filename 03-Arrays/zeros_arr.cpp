//C++ program to push all the zeroes to the right side of the array keeping the order of non zero numbers same

#include<bits/stdc++.h>
using namespace std;

int main() {
    //t is the number of testcases
    int t;
    cin>>t;
    while(t--){ 
        int n; // n is the length of the array
        cin>>n;
        int arr[n]; // this array is for taking array inputs from user
        int arr2[n]; // this array is to store the non zero elements in their order
        for(int i=0;i<n;i++){
            arr2[i]=0; // it is first completely filled with zeroes
        }
	// algo for making arr2
        for(int i=0,j=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]>0){
                arr2[j]=arr[i];
                j++;}
        }
	//printing out the arr2 values
        for(int i=0;i<n;i++){
            cout<<arr2[i]<<" ";
        }
        cout<<endl;
    }
	return 0;
}
