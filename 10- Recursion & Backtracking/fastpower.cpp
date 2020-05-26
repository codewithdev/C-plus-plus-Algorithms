#include<iostream>
using namespace std;
int power(int a, int b){
	if(b==0){
		return 1;
	}
	else{
		if(b&2==0){
		return a*power(a, b-1);
	}
}
int fastPower(int a, int b){

	if(b==0){
		return 1;
	}
	int smallAns= a*fastPower(a,b/2);
	smallAns*= smallAns;
	if(b&1){
		return a*smallAns;
	}
	return smallAns;
}

return 0;
}
int main()
{
	int a,b;cin>>a>>b;
	cout<<power(a,b);
}