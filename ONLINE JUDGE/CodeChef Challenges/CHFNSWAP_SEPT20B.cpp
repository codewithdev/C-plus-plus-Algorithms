#include<bits/stdc++.h>
#define ll long long int
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX_LIMIT 10000000
#define all(x) x.begin(),x.end()
#define br break
#define pb push_back
using namespace std; 
bool isPerfectSquare(long double x)
{
  long double sr = sqrt(x);
  return ((sr - floor(sr)) == 0);
}
void solve(){
 	  //input
 	  ll n;
 	  cin>>n;
 	  ll sum=(n)*(n+1)/2;
 	  ll i;
 	  if(sum&1){
		  cout<<0<<endl;
		  return;
	  }
	  ll z=1+4*sum;
	  ll ans=0;
	  bool flag=0;
	  if(isPerfectSquare(z)){
		  ll x=sqrt(z);
		  ans=(x-1)/2;
		  flag=1;
	  }
	  ll ans1=0;
	  if(flag){
		    ans1+=(n-ans);
		    ans1+=ans*(ans-1)/2;
		    ll v=n-ans;
		    ans1+=v*(v-1)/2;
	  }
	  else{
		  ll g=sqrt(z);
		  ans=(g-1)/2;
		  ans1+=(n-ans);  
	  }
	  cout<<ans1<<endl;
}     
int32_t main()
{	
     fio;
   ll t=1;
   cin>>t;
   while(t--){
   	  solve();
   }
}
