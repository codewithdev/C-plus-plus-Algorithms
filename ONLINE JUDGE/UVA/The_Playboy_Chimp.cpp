#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void solve1();

int main()
{

	solve1();

    return 0;
}
void solve1()
{
	long long t, n, q;
	long long ara[100008];

	cin >> t;
	for(long long i = 0; i < t; i++)
	{
		cin >> ara[i];
	}

	cin >> q;
	while(q--)
	{
		cin >> n;

		//cout << n << endl;
		int f1 = 0, f2 = 0, f = 0;
		for(int i = 0; i < t; i++)
		{
			//cout << ara[i] << endl;
			if(n <= ara[i])
			{
				f = 1;
				for(int j = i; j >= 0; j--)
				{
					if(n > ara[j])
					{
						cout << ara[j];
						f1 = 1;
						break;
					}
				}
				if(f1 == 0)
				{
					cout << "X ";
				}
				else
				{
					cout << " ";
				}

				for(int j = i; j < t; j++)
				{
					if(n < ara[j])
					{
						cout << ara[j];
						f2 = 1;
						break;
					}
				}
				if(f2 == 0)
				{
					cout << "X";
				}
			}
			if(f == 1)
			{
				cout << endl;

				break;
			}
		}

	}
}