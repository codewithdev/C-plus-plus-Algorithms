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
	ll t, x, y;
	cin >> t;

	while(t--)
	{
		cin >> x >> y;
		if(x > y) cout << (x-y) << endl;
		else cout << 0 << endl;
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