#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll countSubsets(ll a[], ll n, ll S) {
    if (n == 0 && S == 0)
        return 1;
    else if (n != 0 && S == 0)
        return 1;
    else if (n == 0 && S != 0)
        return 0;
    if (a[n - 1] <= S) {
        return countSubsets(a, n - 1, S) + countSubsets(a, n - 1, S - a[n - 1]);
    }
    else
        return countSubsets(a, n - 1, S);
}
int main() {
    /*
    Given n as the size of the array and S as the required sum.
    a[i] is the ith element of the array which is >0
    To find:
    The count of subsets having the sum S
    Similar to the subset sum problem, just instead of || use +
    */
    ll n, S;
    cin >> n >> S;
    ll a[n];
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    cout << countSubsets(a, n, S) << endl;

    /*
    INPUT:
    6 10
    2 3 5 6 8 10
    OUTPUT: 
    3
    */
    return 0;
}

