#include<iostream>
using namespace std;
int mul(int a, int b){
	if(a==0 || b==0){
	return 0;	
}
	for(int i=0;i<b;i++){
	int ans=0;
	ans+= mul(a,b);
return ans;
}
return 0;
}


int main(){
	int a,b;cin>>a>>b;
	cout<<mul(a,b);
}
