#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repp(i,a,b) for(ll i=a;i<=b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define endl "\n"
#define deb(x) cerr << #x << "=" << x << endl
#define debb(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define mod ((ll)1e18)
#define N ((ll)2e6+10)
#define pb push_back
#define in insert
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define PI 3.1415926535897932384626
#define all(x) x.begin(), x.end()
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define test ll t; cin>>t; while(t--)
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

/*Functions*/
ll gcd(ll a, ll b);
ll exp(ll x, ll y, ll p);
ll exp(ll x, ll y);
void InverseofNumber();
void InverseofFactorial();
ll Binomial(ll n, ll R);


ll factorialNumInverse[N + 1];
ll naturalNumInverse[N + 1];
ll fact[N + 1];

void fileIO() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

ll n, m;
vector<pll> v[N];
ll ids[N] = {0};
ll dist[N] = {0};
ll vis[N] = {0};

int main() {
    speed
    // InverseofNumber(),InverseofFactorial(),factorial();
    fileIO();

    cin >> n >> m;
    rep(i, 0, m) {
        ll xx, yy, wt; cin >> xx >> yy >> wt;
        v[xx].pb({yy, wt});
    }
    fill(dist, dist + N, mod);
    dist[1] = 0;
    multiset < pair < ll , ll > > s;
    s.in({1, 0});
    while (!s.empty()) {
        pll x = *s.begin();
        s.erase(s.begin());
        vis[x.F] = 1;
        for (auto i : v[x.F]) {
            ll d = dist[x.F] + i.S;
            if (d < dist[i.F]) {
                dist[i.F] = d;
                s.in({i.F, d});
            }
        }

    }
    repp(i, 1, n) {
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}


/*All Functions*/
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

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
ll exp(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y % 2)
            res = (res * x ) ;
        x = (x * x) ;
        y /= 2;
    }
    return res;
}
void InverseofNumber() {
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (ll i = 2; i <= N; i++)
        naturalNumInverse[i] = naturalNumInverse[mod % i] * (mod - mod / i) % mod;
}
void InverseofFactorial() {
    factorialNumInverse[0] = factorialNumInverse[1] = 1;
    for (ll i = 2; i <= N; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % mod;
}
void factorial() {
    fact[0] = 1;
    for (ll i = 1; i <= N; i++)
        fact[i] = (fact[i - 1] * i) % mod;
}
ll Binomial(ll n, ll R) {
    ll ans = ((fact[n] * factorialNumInverse[R]) % mod * (factorialNumInverse[n - R]) % mod) % mod;
    return ans;
}

