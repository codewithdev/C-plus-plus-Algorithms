#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int a[]= {10,20,30,40,50,60,70};
    int n= sizeof(a)/sizeof(int);
    rotate(a,a+3,a+n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    vector <int> v{10,20,30,40,50,60};
    rotate(v.begin(), v.begin()+3, v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}