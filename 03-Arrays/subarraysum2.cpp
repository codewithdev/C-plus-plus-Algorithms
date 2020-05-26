#include<iostream>
using namespace std;
int main()
{
    int n;cin>>n;
    int a[1000];
    int currentsum=0;
    int maxsum=0;
    int left=-1;
    int right=-1;
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
            if(currentsum>maxsum){
                maxsum= currentsum;
                left=i;
                right=j;
            }
        }
        cout<<endl;
    }
cout<<"Maximum Sum is "<<maxsum<<endl;
for(int k=left;k<=right;k++)
{
    cout<<a[k]<<",";
}
return 0;
}
