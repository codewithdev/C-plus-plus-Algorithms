#include<iostream>
using namespace std;
#define ll long long
void primesieve(int *p){
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
	int p[1000005]={0};
	int csum[100000]={0};
	primesieve(p);
	int q;cin>>q;
	for(int i=1;i<=1000000;i++){
		csum[i]= csum[i-1]+p[i];
	}
	while(q--){
		int a,b;cin>>a>>b;
		cout<<csum[b]-csum[a-1]<<endl;
	}
}