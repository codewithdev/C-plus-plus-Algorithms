#include<bits/stdc++.h>
using namespace std;
bool minHeap= false;
bool compare(int a, int b){
  if(minHeap){
  	return a<b;
  }
  else{
  	return a>b;
  }
}
void heapify(std::vector<int> &v, int index, int size){
	int left= 2*index;
	int right= left+1;
	int min_index= index;
	int last= size-1;
	if(left<=last and compare(v[left],v[index])){
       min_index= left;
	}
	if(right<=last and compare(v[right],v[min_index])){
		min_index= right;
	}
	if(min_index!= index){
		swap(v[index],v[min_index]);
		heapify(v,min_index,size);
	}
}
void buildHeap(std::vector<int>v){
	for(int i=v.size()-1/2;i>=1;i--){
		heapify(v,i,v.size());
	}
}

void heapSort(std::vector<int> &v){
	buildHeap(v);
	int n= v.size();
	// remove n-1 element from the heap

	while(n>1){
		swap(v[1],v[n-1]);
		//remove the element from the heap
		n--;
		heapify(v,1,n);
	}
}
void print(std::vector<int>v){
	for(int x=1;x<v.size();x++){
		cout<<v[x]<<" ";
	}
	cout<<endl;
}

int main(){
	std::vector<int>v;
	v.push_back(-1);
	int n;
	cin>>n;
	int temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		v.push_back(temp);
	}
	heapSort(v);
	print(v);
}