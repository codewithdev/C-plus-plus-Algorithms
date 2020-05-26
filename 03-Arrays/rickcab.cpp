#include<iostream>
using namespace std;
int main()
{
    int t;cin>>t;
    int rick[1005],cab[1005];

    while(t--)
    {
        int m,n,c1,c2,c3,c4;cin>>c1>>c2>>c3>>c4;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            cin>>rick[i];
        }
        for(int i=0;i<m;i++)
        {
            cin>>cab[i];
        }
        int rickcost=0;
        for(int i=0;i<n;i++)
        {
            rickcost+= min(c1*rick[i],c2);
        }
        rickcost= min(rickcost,c3);
        int cabcost=0;
        for(int i=0;i<m;i++)
        {
            cabcost+= min(c1*cab[i],c2);
        }
        cabcost= min(cabcost,c3);
        int finalAns= min(c4, rickcost+cabcost)
        cout<<finalAns<endl;
    }
}