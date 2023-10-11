#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void solve();

int main()
{

	solve();

    return 0;
}

void solve()
{
	int t, cs = 1, mx, n, m;

	cin >> t;

	while(t--)
	{
		mx = 0;
		cin >> n;
		while(n--)
		{
			cin >> m;
			if(mx < m)
			{
				mx = m;
			}
		}
		cout << "Case " << cs++ << ": " << mx << endl;
	}
}

