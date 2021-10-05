// Problem URL : https://atcoder.jp/contests/dp/tasks/dp_d

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define all(v)          v.begin(),v.end()
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define rep(i,a,b)      for(int i=a;i<b;i++)
#define mem1(a)         memset(a,-1,sizeof(a))
#define mem0(a)         memset(a,0,sizeof(a))
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

template<typename T, typename T1>T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1>T amin(T &a, T1 b) {if (b < a)a = b; return a;}
template<typename T>
using pbds = tree<T , null_type , less<T> , rb_tree_tag , tree_order_statistics_node_update>;
const int N = 1e5 + 5;

void solve() {
    int n, W; cin >> n >> W;
    vi w(n + 1), v(n + 1);

    //take the weights and value as input
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    vector<vector<int>>dp(n + 1, vi(W + 1));
    // dp[i][j] = maximum value possible if we consider first 'i' items and total weight of those items not exceed 'j' 


    // iterate over every item
    for (int i = 1; i <= n; i++) {

        for (int j = 0; j <= W; j++) {

            // two possibilities - 

            // either not take ith item in knapsack
            dp[i][j] = dp[i - 1][j];

            // take the ith item in knapsack
            if (j - w[i] >= 0)
                amax(dp[i][j], v[i] + dp[i - 1][j - w[i]]);
        }
    }

    cout << dp[n][W] << endl;
}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#ifdef SEIVE
    seive();
#endif
#ifdef NCR
    init();
#endif
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;

}
