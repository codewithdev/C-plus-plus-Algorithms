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
		ll a, b;
		cin >> a >> b;

		if(b-a == 1 || b-a == 3) cout << "YES" << endl;
		else if(b-a == 2) cout << "NO" << endl;
		else
		{
			if((b-a)%3 == 0 || (b-a)%3 == 1) cout << "YES" << endl;
			else cout << "NO" << endl;
			// if(a%2 == 0 && b%2 == 0)
			// else if(a%2 != 0 && b%2 != 0)
			// else if(a%2 == 0 && b%2 != 0)
			// else if(a%2 != 0 && b%2 == 0)
		}
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

// 2 -> 3, 5, 6, 8, 9, 11, 12
// 3 -> 4, (6, 7,) (9, 10,) (12, 13)
// 4 -> 5, 7, 8, 10, 11, 13, 14