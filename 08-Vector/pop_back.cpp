#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>v{1,2,3,4,5,6,19};
	v.pop_back();
	for(int x:v){
		cout<<x<<",";
	}
}