#include<iostream>
using namespace std;
int main()
{
    int n;cin>>n;
    int a[1000];
    int currentsum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            currentsum=0;
            for(int k=i;k<=j;k++)
            {
                currentsum+= a[k];
            }
            cout<<currentsum<<",";
        }
        cout<<endl;
    }
}