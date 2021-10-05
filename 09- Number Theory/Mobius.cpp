#include <bits/stdc++.h>

using namespace std;

vector<int> mobius(int n) {
    vector<int> prime;
    vector<int> mu(n + 1);
    vector<bool> isComposite(n + 1, false);
    mu[1] = 1;
    for (int i = 2; i < n; ++i) {
        if (!isComposite[i]) {
            prime.push_back(i);
            mu[i] = -1;
        }
        for (int j = 0; j < prime.size() && i * prime[j] <= n; ++j) {
            isComposite[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                break;
            } else {
                mu[i * prime[j]] = mu[i] * mu[prime[j]];
            }
        }
    }
    return mu;
}

signed main() {
    int n;
    cin >> n;
    vector<int> mu = mobius(n);
    for (int i : mu) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}