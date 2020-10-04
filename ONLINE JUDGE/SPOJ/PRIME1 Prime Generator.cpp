#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long int m,n;
        cin>>m>>n;
        for(int i=m;i<=n;i++)
        {   
            int flag=0;
            for(int j=2;j<=sqrt(i);j++)
            {
                if(i%j==0)
                {
                    flag=1;
                    break;
                }
            }
            if(!flag&&i>=2)
                cout<<i<<endl;
        }
    }
    cout<<endl;
}