#include<iostream>
#include<vector>
using namespace std;
void print(std::vector<int> v){
	for(auto x:v){
		cout<<x<<" ";
	}
}
void buildHeap(std::vector<int> &v){
	for(int i=2;i<v.size();i++){
	int idx=i;
	int parent= i/2;
	while(idx>1 and v[idx]>v[parent]){
		swap(v[idx],v[parent]);
		idx= parent;
		parent= parent/2;
	}
}
}
int main()
{
	std::vector<int> v{-1,20,3,4,19,18,45,7};
	print(v);
	cout<<endl;
	buildHeap(v);
	print(v);
}
