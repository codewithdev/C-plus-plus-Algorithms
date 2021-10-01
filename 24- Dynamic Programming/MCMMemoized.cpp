#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repp(i,a,b) for(ll i=a;i<=b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define endl "\n"

ll dp[1001][1001];
ll MCM(ll a[], ll i, ll j) {
    /*
    The complete logic
    Take the array: 40 20 30 10 30
    Feel where to apply MCM. It should be applied where you feel you really don't
    know what the answer is but feel like I have to partition at each point and check
    which of them is the minimum.
    The basic format of all MCM's is similar. Base condition needs to be thought about.
    For the base condition think of the first invalid input. That will be it.
    Now talking about the for loop.
    In this we check for each k from i to j-1.
    Selecting i and j at the starting is also very crucial. It can be selected by taking
    an example and trial and error.
    In this case if you initially take i to be 0, we get an invalid matrix as,
    general matrix Ai=a[i-1]*a[i]. So i needs to be 1. Similarly j=n-1.
    In the loop we partition at each k and find the smallest answer.
    Now how does the last a[i - 1] * a[k] * a[j] thing come.
    This comes because say we have, ((AB)(CD)).
    After solving the inner braces we get (EF). It's answer should also be added to the
    final ans.
    How to find it?
    ->Observe A starts at index i and ends at k, C starts at k+1 and ends at j.
    So the dimensions are preserved for these entities... Think on this.
    You'll get the hang of it.
    It's OP;)

    */
    if (i >= j)
        return 0LL;
    if (dp[i][j] != -1)
        return dp[i][j];
    ll ans = LLONG_MAX;
    for (ll k = i; k <= j - 1; k++) {
        ll tempAns;
        tempAns = MCM(a, i, k) + MCM(a, k + 1, j) + a[i - 1] * a[k] * a[j];
        ans = min(ans, tempAns);
    }
    return dp[i][j] = ans;
}
int main() {
    /*
    MATRIX CHAIN MULTIPLICATION( aka MCM)
    Given:
    An integer n denoting the size of the array
    a[i] is the ith array element.
    Let array be:
    40 20 30 10 30
    It represents n-1 2D matrices viz.
    A1= 40*20
    A2=20*30
    A3=30*10
    A4=10*30
    In short Ai= a[i-1]*a[i] size matrix.
    We need to given the minimum cost of multiplying these matrices.
    Cost Eg:
    40*20 and 20*30 matrix are to be multiplied
    -> Cost= 40*20*30
    The cost differs by how you multiply the matrices
    Eg:
    Let the matrices be ABCD.
    ((AB)(CD)) can have different cost than ((ABC)D).
    */
    ll n; cin >> n;
    ll a[n];
    rep(i, 0, n) cin >> a[i];
    ll i = 1, j = n - 1;
    memset(dp, -1, sizeof(dp));
    cout << MCM(a, i, j);

    return 0;
}
