#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll compute_hash(string s){
	const int p= 3;
	const int m= 1e9+9;
	ll hash_value= 0;
	ll p_pow= (ll)pow(p,s.length()-1);
	for(auto c:s){
		hash_value= (hash_value+ (c-'a')*p_pow)%m;
		p_pow= p_pow/p;
	}
	return hash_value;
}
ll rolling_hash(ll H,string prev,char nxt)
{
   const int p = 31;
   const int m = 1e9 + 9;
   ll Hnxt=( ( H - (prev[0]-'a')*(ll)pow(p,prev.length()-1) ) * p + (nxt-'a') ) % m;
   return Hnxt;
}
bool is_substring(string s1,string s2){
	int j=0;
	string prev= s1.substr(j,s2.length());
	j++;
	map<ll,int>m1,m2;
	ll h2= compute_hash(s2);
	ll h1= compute_hash(s1);
	m1[h1]=1;
	m2[h2]=1;

	for(int i=s2.length();i<s1.length();i++){
		h1= rolling_hash(h1,prev,s1[i]);
		m1[h1]=1;
	prev=s1.substr(j,s2.length());
        j++;
    }
    return m1[h2]==m2[h2];
}
int main()
{
	string s1= "iitian";
    string s2= "iiti";
	if(is_substring(s1,s2)) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;

}

