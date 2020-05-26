#include<iostream>
using namespace std;
int gcdofnumbers(int a, int b){
	return b==0?a:gcdofnumbers(b,a%b);
}
int lcmofnumbers(int a,int b){
	int lcm=0;
	int product= 0;
	if(a>0 and b>0){
		product+= a*b;
        lcm= product/gcdofnumbers(a,b);
	}
	return lcm;

}
int main()
{
	int a,b;cin>>a>>b;
	cout<<lcmofnumbers(a,b);
}