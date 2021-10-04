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
#define N ((ll)2e6)
#define pb push_back
#define in insert
#define F first
#define S second
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define PI 3.1415926535897932384626
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define test ll t; cin>>t; while(t--)
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
ll dr[] = { -1, 1, 0, 0};
ll dc[] = {0, 0, 1, -1};

/*Functions*/
ll gcd(ll a, ll b);
ll exp(ll x, ll y, ll p);
ll exp(ll x, ll y);
void InverseofNumber();
void InverseofFactorial();
void factorial();
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
ll n, m; //no of vertices and number of edges
vector<ll> v[N]; //the graph representation
ll vis[N]; //visited array
ll color[N]; //color array
bool dfs(ll x, ll c) {
    vis[x] = 1;
    color[x] = c;
    for (auto i : v[x]) {
        if (vis[i] == 0) {
            if (dfs(i, c ^ 1) == false) //invert color
                return false;
        }
        else {
            if (color[x] == color[i])
                return false;
        }
    }
    return true;
}
int main() {
    speed
    // InverseofNumber(),InverseofFactorial(),factorial();
    fileIO();
    cin >> n >> m;
    while (m--) {
        ll xx, yy; cin >> xx >> yy;
        v[xx].pb(yy);
        v[yy].pb(xx);
    }
    ll ans = 0;
    bool answer;
    for (ll i = 1; i <= n; i++) {
        if (!vis[i]) {
            answer = dfs(i, 0); //dfs calls for unvisited nodes
            if (!answer) {
                cout << "NOT BIPARTITE" << endl;
                exit(0);
            }
        }
    }
    cout << "BIPARTITE" << endl;

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
