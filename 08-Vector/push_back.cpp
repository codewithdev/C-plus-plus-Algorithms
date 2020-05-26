#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>v{1,2,3,4,5,6};
	v.push_back(10);
	for(int x:v){
		cout<<x<<",";
	}
}