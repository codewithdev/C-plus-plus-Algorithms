#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>v{1,2,3,4,5,14};
	v.insert(v.begin()+3, 3, 100);
	for(int x:v){
		cout<<x<<",";
	}
}