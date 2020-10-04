#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int checkDist(long long int maxdist,vector <long long int> arr, int c)
{
    int left=0;
    c--;
    for(int i=1;i<arr.size();i++)
    {
        if((arr[i]-arr[left])>=maxdist)
        {
            c--;
            left=i;
        }
    }
    if(c<=0)
        return 1;
    else
        return 0;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,c;
        cin>>n>>c;
        vector <long long int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr.begin(),arr.end());
        int left = arr[0],right = arr[n-1];
        long long int maxdist = left + (right-left)/2;
        long long int ans=0;
        while(left<=right)
        {
            //cout<<maxdist<<endl;
            if(checkDist(maxdist,arr,c)==1)
            {
                if(maxdist>ans)
                    ans=maxdist;
                left=maxdist+1;
                maxdist=left + (right-left)/2;
            }
            else
            {
                right = maxdist-1;
                maxdist = left + (right-left)/2;
            }
        }
        cout<<ans<<endl;
    }
}