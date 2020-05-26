#include<iostream>
using namespace std;
int binarySearch(int a[],int n,int key){
    int s=0,e=n-1;
    int mid;
    while(s<=e){
        mid= (s+e)/2;
        if(a[mid]==key){
            return mid;
        }
        //Key Might be present in the left
        else if(a[mid]>key){
            e= mid-1;
        }
        //Key Might be present in the right
        else{
            s=mid+1;
        }
    }
    return -1;
}
int  main()
{
    int a[]= {1,2,4,8,12,14,18,20,22};
    int n= sizeof(a)/sizeof(int);
    int key;
    cin>>key;
    int SearchIndex= binarySearch(a,n,key);
    if(SearchIndex==-1){
        cout<<key<<"is not present"<<endl;
    }
    else{
        cout<<key<<"Is present at Index "<<SearchIndex<<endl;
    }
}