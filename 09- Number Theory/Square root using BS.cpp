// This algorithm finds the sqaure root 
// of a number using Binary Search in 
// O(logN) time .

#include <bits/stdc++.h>
using namespace std;

int bschsqrt(int n, float precs) {
	float l = 0, r = n, mid;
	while (r - l > precs) {
		mid = l + (r - l) / 2;
		if (mid * mid < n)
			l = mid;
		else
			r = mid;
	}
	return l + (r - l) / 2;
}

int main() {
    int n;
    float precision = 0.0001, sqrtn;
    cin >> n;
    sqrtn = bschsqrt(n, precision);
    cout << sqrtn << '\n';
}