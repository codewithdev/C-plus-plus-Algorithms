#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb(x) push_back(x)

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
	ll t;
	cin >> t;
	while(t--)
	{
		ll n, x;
		cin >> n >> x;

		if(n <= 6) cout << x << endl;
		else cout << int(ceil(n/6.0)*x) << endl;
	}
}
void setup()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#else
	#endif
}