#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()


{
	int t;cin>>t;
	int run=0;
    vector<pair<int,int>>v;
    for(int i=0;i<t;i++){
    	int x,y;
    	cin>>x>>y;
    	v.push_back(make_pair(x,y));
    }
    sort(v.begin(), v.end());
    for(auto p:v){
    	run+= (p.first- p.second);
    	cout<run<<endl;
    	
}
    }



