#include<iostream>
using namespace std;
int main()
{
    int n;cin>>n;
    char a[10][10000];
    cin.ignore();
    for(int i=0;i<n;i++)
    {
        cin.getline(a[i],10000);
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
}