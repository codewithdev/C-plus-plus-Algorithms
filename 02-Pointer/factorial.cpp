#include<iostream>
using namespace std;
int fact(int n)
{
    int ans=1;
    for(int i=1;i<=n;i++)
    {
        ans= ans*i;
    }
    return ans;
}
 int NCR(int n, int r)
 {
     int ans= fact(n)/ fact(n-r) * fact(r);
     return ans; 
 }
int main()
{
    cout <<fact(5)<<endl;
    cout<<NCR(9,2)<<endl;
}