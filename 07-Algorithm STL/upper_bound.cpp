#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;cin>>n;
    int a[1000];
    for(int i=0;i<n;i++){
    	cin>>a[i];

    }
    int key;cin>>key;
    auto it= lower_bound(a,a+n,key);
    int lb= it-a;
    auto it2= upper_bound(a,a+n,key);
    int ub= it-a;

    cout<<"Occurrence of "<<key<<"is :"<<(ub-lb)<<endl;

}