#include <iostream>

using namespace std;
typedef long long ll;
ll mx = 0;

void fn(ll n);
int main()
{
    ll i, j, tmp;

    while(cin >> i >> j)
    {
        cout << i << " " << j;
        if(j < i)
        {
            tmp = i;
            i = j;
            j = tmp;
        }
        for(ll k = i; k <= j; k++)
        {
            fn(k);
        }
        cout << " " << mx << endl;
        mx = 0;
    }

    return 0;
}
void fn(ll n)
{
    ll c = 0;
    while(n != 1)
    {
        c++;
        if(n == 1)
        {
            break;
        }
        if(n%2 == 0)
        {
            n /= 2;
        }
        else
        {
            n = n*3 + 1;
        }
    }
    c++;
    if(c >= mx)
    {
        mx = c;
    }
}