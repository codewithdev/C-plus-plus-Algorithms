#include<iostream>
using namespace std;
#define ll long long
void primeSieve(int *p){
	for(int i=3;i<=1000000;i+=2){
		p[i]=1;
	}
	//Sieve

	for(ll i=3;i<=1000000;i+=2){
		if(p[i]==1){
			for(ll j=i*i;j<=1000000;j++){
				p[j]=0;
			}
		}
	}
	//special Case
	p[2]=1;
	p[1]=p[0]=0;
}
int main()
{
	int n;cin>>n;
	int p[100005]= {0};
	primeSieve(p);
	for(int i=0;i<=n;i++){
		if(p[i]==1){
			cout<<i<<" ";
		}
	}
	return 0;
}