// This algorithm will print all
// the Prime Factors of a number.

// Time Complexity -> O(sqrt(N))
// Space Complexity -> O(1)

#include <bits/stdc++.h>
using namespace std;

void primeFactorization(int n) {
	for (int i = 2; i * i <= n; i++) {
		int cnt = 0;
		while (n % i == 0) {
			cnt++;
			n /= i;
		}
		cout << i << " ^ " << cnt << "\n";
	}
	if (n > 1)
		cout << n << " ^ " << 1 << "\n";
}

int main() {
    int n;
    cin >> n;
    primeFactorization(n);
    return 0;
}