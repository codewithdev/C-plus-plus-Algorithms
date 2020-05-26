#include "bits/stdc++.h"
#define mod 1000000007
#define nn 100010
 
using namespace std;
​
int main()
{
    int n;
    string s;
    cin>>s;
    n=s.length();
    string pr;
    for(int i=0;i<n;i++)
    {
        pr.push_back(s[i]);
        if(i==n-1) //last letter
            cout<<pr<<endl;
        else if(s[i+1]>='A' && s[i+1]<='Z') //s[i+1] is a capital letter.
        {
            cout<<pr<<endl;
            pr.clear();
        }
    }
    return 0;
}