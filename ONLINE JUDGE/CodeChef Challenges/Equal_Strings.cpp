#include <bits/stdc++.h>
#include <math.h>
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
		ll n;
		string s1, s2;

		cin >> n >> s1 >> s2;

		ll ss1 = s1.size(), ss2 = s2.size();

		set <char> s;
		ll c = 0;
		for(ll i = 0; i < ss1; i++)
		{
			if(s1[i] != s2[i])
			{
				c++;
				s.insert(s2[i]);
			}
		}

		// cout << c << " " << s.size() << endl;
		// for (auto itr : s)
		//   {
		//     cout << itr << " ";
		//   }
		//   cout << endl;
		if(c > s.size()) cout << s.size() << endl;
		else cout << c << endl;

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

