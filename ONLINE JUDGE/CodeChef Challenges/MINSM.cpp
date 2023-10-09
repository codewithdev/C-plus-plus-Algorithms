
#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define frp(a, b) for(ll i = a; i < b; i++)
#define frn(a, b) for(ll i = a; i > b; i--)

#define in(x)     insert(x)
#define pb(x)     push_back(x)
#define full(x)   x.begin(),x.end()

ll gcd(ll a, ll b);
void setup();
void solve();

int main()
{
	setup();
	solve();
	return 0;
}

void solve()
{
	ll T, N;
	cin >> T;
	while(T--)
	{
	    cin >> N;
	    
	     vector <ll> v(N);
	     
	     frp(0, N) cin >> v[i];
	     
	     sort(v.begin(), v.end());

	     ll g = v[0];

	     for(ll j = 1; j < N; j++) g = gcd(g, v[j]);

	     cout << g*N << endl;

	}
}

ll gcd(ll a, ll b)
{
	if(a%b == 0) return b;
	else return gcd(b, a%b);
}
void setup()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("one.txt", "w", stdout);
	#else
	#endif
}