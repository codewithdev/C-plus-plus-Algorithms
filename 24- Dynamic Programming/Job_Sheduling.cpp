#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define push_back pb
#define pair<int,int> pp
bool sortbyfinish(pp p1,pp p2)
{
	return p1.second<p2.second;
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
    	for(int i=0;i<n;i++)
    		cin>>start[i];
    	for(int i=0;i<n;i++)
    		cin>>finish[i];
    	vector<pair<int,int>>activities;
    	for(int i=0;i<n;i++)
    	{
    		activities.pb({i,finish[i]});
    	}
    	sort(activities.begin(),activities.end(),sortbyfinish);
    	vector<int>ans;
    	int i=0;  //myprevious scheduled job
    	ans.push_back(activities[i].first);
    	for(int j=1;j<n;j++)
    	{
    		int nextcompa=activities[j].first;
    		if(start[nextcompa]>=activities[i].second)
    		{
    			i=j;
    			ans.push_back(activities[i].first);
    		}
    	}
        for(int i=0;i<ans.size();i++)
        	cout<<ans[i]<<endl;
    }
return 0;
}