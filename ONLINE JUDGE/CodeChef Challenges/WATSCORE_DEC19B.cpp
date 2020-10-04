#include <iostream>
using namespace std;

int main()
{
    int t,i , tc,n,s[8]={0,0,0,0,0,0,0,0},p[1000],sc[1000],sum;
    cin>>tc;
    for(t=0;t<tc;++t)
    {
        cin>>n;
        for(i=0;i<n;++i)
        {
            cin>>p[i]>>sc[i];
            if((sc[i]>s[p[i]-1])&&p[i]<9&&p[i]>0)
            {
                s[p[i]-1]=sc[i];
            }
        }
        sum=0;
        for(i=0;i<8;++i)
        {
            sum+=s[i];
            s[i]=0;
        }
        cout<<sum<<endl;
        
    }
    return 0;
}
