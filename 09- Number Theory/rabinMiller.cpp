#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repp(i,a,b) for(ll i=a;i<=b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define endl "\n"

ll k = 6;
ll exp(ll x, ll y, ll p) {
    ll res = 1;
    while (y) {
        if (y % 2)
            res = (res * x % p) % p;
        x = (x * x) % p;
        y /= 2;
    }
    return res;
}

bool miller(ll d, ll n) {
    ll a = 2 + rand() % (n - 4);
    ll x = exp(a, d, n);
    if (x == 1 || x == n - 1)
        return true;
    while (d != n - 1) {
        x = (x * x) % n;
        d = d * 2;
        if (x == 1) return false;
        if (x == n - 1) return true;
    }
    return false;
}
bool isPrime(ll n) {
    if (n < 2 || n == 4) return false;
    if (n <= 3) return true;
    ll d = n - 1;
    while (!(d & 1)) {
        d /= 2;
    }
    rep(i, 0, k) {
        if (!miller(d, n))
            return false;
    }
    return true;
}
int main() {

    ll n; cin >> n;
    cout << isPrime(n);
    return 0;
    
}



