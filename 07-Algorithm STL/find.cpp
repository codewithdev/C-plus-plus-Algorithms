#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int arr[]= {10,20,30,14,155};
    int n= sizeof(arr)/sizeof(int);
    int key;
    cin>>key;
    auto it= find(arr,arr+n,key);
    int index= it-arr;
    if(key==n){
        cout<<"Key not found"<<endl;
    }
    else{
    cout<<index<<endl;
}
}
