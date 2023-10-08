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
	int t;
	string s;

	cin >> t;

	while(t--)
	{
		cin >> s;

		int ss = s.size(), f = 0, c = 0;

		for(int i = 0; i < ss; i++)
		{
			if(s[i] == 49)
			{
				c++;
				f = i;
			}
		}

		if(c == 0)
		{
			cout << "NO" << endl;
		}
		else
		{
			for(int i = f; i >= 0; i--)
			{
				if(s[i] == 48)
				{
					break;
				}
				else
				{
					c--;
				}
			}

			//cout << c << endl;
			if(c == 0)
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
		}
		
	}
}