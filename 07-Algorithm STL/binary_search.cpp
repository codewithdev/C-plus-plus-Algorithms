#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;cin>>n;
	int a[1000];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
   int key;cin>>key;
   
   bool present= binary_search(a, a+n, key);
   if(present){
   	cout<<"Present"<<endl;
   }
   else{
   	cout<<"Not Present"<<endl;
   }
}