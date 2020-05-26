#include<iostream>
using namespace std;

#define ll long long  

 int main()

 {
 	ll t;
 	cin>>t;
 	ll prime[]= {2,3,5,7,11,13,17,19};
 	while(t--){
 		ll n;
 		cin>>n;
 		ll ans=0;

 		ll subset= (1<<8)-1;
       
       for(ll i=0;i<=subset;i++){

       	ll denom= 1ll;
       	ll setBits= __builtin_popcount(i);

       	for(ll j=0;j<=7;j++){
       		if(i&(1<<j)){
       			denom= denom* prime[j];
       		}
       	}
       	if(setBits&1){
       		ans+= n/denom;
       	}
       	else{
       		ans-= n/denom;
       	}

       }
       cout<<ans;
 	}
 	return 0;

 }