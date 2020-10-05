// This code will have a complexity of O(log b), but
// we can use __int128 in C++ to avoid any potential
// overflows and work in O(1).
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll binaryMultiplication(ll a, ll b) {
	ll x = 0, y = a;
	while (b > 0) {
		if (b & 1)
			x = (x + y);
		y = (y + y);
		b >>= 1;
	}
	return x;
}

int main() {
    ll a, b;
    cin >> a >> b;
    // Finding a^b
    cout << binaryMultiplication(a, b) << endl;
    return 0;
}