#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;cin>>n;
	int a[1000];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int key;cin>>key;

	auto it= lower_bound(a,a+n, key);
	int index= it-a;
	cout<<"Lower Bound of "<<key<<"is: "<<index<<endl;
}