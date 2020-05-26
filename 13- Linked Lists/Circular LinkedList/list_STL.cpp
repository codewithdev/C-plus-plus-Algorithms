#include<iostream>
#include<list>
using namespace std;
int main()
{
	int n;cin>>n;
	list<int>l;
	for(int i=0;i<n;i++){
    int temp;cin>>temp;
	l.push_back(temp);
}
for(auto s:l){
	cout<<s<<"-->";
}
}