#include<iostream>
using namespace std;
int main()
{
    int a[]= {1,3,4,2,7,8};
    int n= sizeof(a)/sizeof(int);
    for(int i=0;i<n;i+=2){
        //check for the left element
        if(i>0 && a[i-1]>a[i]){
            swap(a[i],a[i-1]);
        }
        //check for right element
        if(i<n-2 && a[i+1]>a[i]){
            swap(a[i+1],a[i]);
        }
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
    }
}
