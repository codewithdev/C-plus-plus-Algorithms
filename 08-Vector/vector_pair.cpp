#include<iostream>
#include<vector>
#include<algorithm>
bool compare()
using namespace std;
int main()
{
	int n;cin>>n;
	vector<pair<int,int>>v;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		v.push_back(make_pair(x,y));
	}
	sort(v.begin(),v.end());
	for(auto p:v){
		cout<<p.first<<","<<p.second<<endl;
	}
}