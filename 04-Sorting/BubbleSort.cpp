#include<iostream>
using namespace std;
int main()
{
    int n;cin>>n;
    int a[n];
    int temp=0;
    for(int i=0;i<n;i++){
        cin<<a[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n-1;j++){
            if(a[i]>a[j]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}