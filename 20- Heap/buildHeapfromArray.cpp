#include<iostream>
#include<vector>
using namespace std;
bool minHeap= false;
bool compare(int a , int b){
	if(minHeap){
		return a<b;
	}
	else{
		return a>b;
	}
}
void heapify(std::vector<int> &v, int index){
	int left= 2*index;
	int right= left+1;
	int min_index= index;
	int last= v.size()-1;
	if(left<=last and compare(v[left],v[index])){
		min_index= left;
	}
	if(right<=last and compare(v[right],v[min_index])){
		min_index= right;
	}
	if(min_index!=index){
		swap(v[index],v[min_index]);
		heapify(v,min_index);
	}
}
void print(std::vector<int>v){
	for(auto x:v){
		cout<<x<<" ";
	}
}

void buildHeap(std::vector<int>&v){
	for(int i= v.size()-1/2;i>=1;i--){
       heapify(v,i);
	}
}
int main(){



	std::vector<int> v{-1,10,2,4,9,11,8,5};
	print(v);
	buildHeap(v);
	cout<<endl;
	print(v);
}