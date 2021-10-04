#include<bits/stdc++.h>
// #warning x&1=0 if x is even and x&1=1 if x is odd
// #include<ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pdbs;
using namespace std;
#define ll long long
#define rep( i,  a,  b) for(ll i=a;i<b;i++)
#define repp(i,a,b) for(ll i=a;i<=b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define ld long double
#define endl "\n"
#define mod ((ll)1e18)
#define N ((ll)2e6+10)
#define pb push_back
#define in insert
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define test ll t; cin>>t; while(t--)
ll gcd(ll a, ll b) {if (b == 0)return a; return gcd(b, a % b);}
ll exp(ll x, ll y, ll p) { ll res = 1; while (y) {if (y % 2) res = (res * x % p) % p; x = (x * x) % p; y /= 2; } return res;}
ll exp(ll x, ll y) { ll res = 1; while (y) {if (y % 2) res = (res * x ) ; x = (x * x) ; y /= 2; } return res;}
ll sv[1000000] = {0};
ll factorialNumInverse[N + 1];
ll naturalNumInverse[N + 1];
ll fact[N + 1];
void InverseofNumber() {naturalNumInverse[0] = naturalNumInverse[1] = 1; for (ll i = 2; i <= N; i++)naturalNumInverse[i] = naturalNumInverse[mod % i] * (mod - mod / i) % mod;}
void InverseofFactorial() {factorialNumInverse[0] = factorialNumInverse[1] = 1; for (ll i = 2; i <= N; i++)factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % mod;}
void factorial() {fact[0] = 1; for (ll i = 1; i <= N; i++) {fact[i] = (fact[i - 1] * i) % mod;}}
ll Binomial(ll n, ll R) {ll ans = ((fact[n] * factorialNumInverse[R]) % mod * (factorialNumInverse[n - R]) % mod) % mod; return ans;}
/*TOIENT FUNCTION*/ll phi(ll n) {ll ans = n; for (ll i = 2; i * i <= n; i++) {if (n % i == 0) {while (n % i == 0) n /= i; ans -= ans / i;}} if (n > 1) ans -= ans / n; return ans;}


void fileIO() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
ll n, k; ll vis[N] ;
ll counter = 0;
ll component[N];
vector<ll> v[N];
void dfs(ll at) {
    if (vis[at] == 1) return;
    vis[at] = 1;
    component[at] = counter;
    for (auto i : v[at]) {
        dfs(i);
    }
}

int main() {
    speed
    // InverseofNumber(),InverseofFactorial(),factorial();
    fileIO();
    cin >> n >> k;
    rep(i, 0, k) {
        ll xx, yy; cin >> xx >> yy;
        v[xx].pb(yy);
        v[yy].pb(xx);
    }
    fill(vis, vis + N, 0);
    repp(i, 1, n) {
        if (!vis[i]) {
            counter++;
            dfs(i);
        }
    }
    repp(i, 0, n) {
        cout << component[i] << " ";
    }
    cout << endl;


    return 0;
}
