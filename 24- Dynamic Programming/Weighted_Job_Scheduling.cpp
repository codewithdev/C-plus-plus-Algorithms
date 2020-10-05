#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back 
#define pp pair<int,int>
struct interval
{
    int start;
    int finish;
    int weight;
};
bool sortbyfinish(interval p1,interval p2)
{
	return p1.finish<p2.finish;
}
int nextcompatible(vector<interval> &arr,int i)
{
    for (int j=i-1; j>=0; j--) 
    { 
        if (arr[j].finish <= arr[i].start) 
            return j; 
    } 
    return -1; 
}
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
    	int n;
    	cin>>n;
    	int start[n];
    	int finish[n];
        int weight[n];
    	for(int i=0;i<n;i++)
    		cin>>start[i];
    	for(int i=0;i<n;i++)
    		cin>>finish[i];
        for(int i=0;i<n;i++)
            cin>>weight[i];
        vector<interval> arr;
        for(int i=0;i<n;i++)
        {
            arr.push_back({start[i],finish[i],weight[i]});
        }
        sort(arr.begin(),arr.end(),sortbyfinish);
        vector<int> dp(n,0);
        dp[0]=arr[0].weight;
        for(int i=1;i<n;i++)
        {
            int include=arr[i].weight;
            int exclude=dp[i-1];
            int findnext=nextcompatible(arr,i);
            if(findnext!=-1)
                include+= dp[findnext];
            dp[i]=max(include,exclude);
        }
        cout<<"Maximum profit that can be obtained : "<<endl;
        cout<<dp[n-1]<<endl;
    }
        return 0;
}