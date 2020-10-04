#include <iostream>
using namespace std;

int main()
{
    int t,i,j , tc,n, arr[40000],ctr=0;
    cin>>tc;
    for(t=0;t<tc;++t)
    {
        cin>>n;
        for(i=0;i<n;++i)
        {
            cin>>arr[i];
        }
        for(i=0;i<n;++i)
        {
            for(j=i+1;j<n;++j)
            {
                if((arr[i]+arr[j])==(arr[i]*arr[j]))
                {
                    ctr++;
                    //cout<<endl<<i<<"\t"<<j<<"\t"<<ctr<<endl;
                }
            }
        }
        cout<<ctr<<endl;
        ctr=0;
        
    }
    return 0;
}
