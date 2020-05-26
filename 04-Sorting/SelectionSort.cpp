#include<iostream>
using namespace std;
int main()
{
    int n;cin>>n;
    int a[n];
    int temp=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<=n-1;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
         if(a[minIndex]>a[j]){
             temp=a[minIndex];
             a[minIndex]=a[j];
             a[j]=temp;
         }
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}