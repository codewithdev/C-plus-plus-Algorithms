#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool equalSumPartition(ll a[], ll n, ll S) {
    if (n == 0 && S == 0)
        return 1;
    if (n == 0 && S != 0)
        return 0;
    if (n != 0 && S == 0)
        return 1;
    if (a[n - 1] <= S) {
        return equalSumPartition(a, n - 1, S) || equalSumPartition(a, n - 1, S - a[n - 1]);
    }
    else
        return equalSumPartition(a, n - 1, S);
}
int main() {
    /*
    Given Input:
    n denotes the number of elements in the array
    a[i] is the ith element of the array
    S is the sum of the array
    To find:
    Return True if the array can be divided into 2 subsets of equal sum else return false


    Interpretations:
    Problem is similar to 0-1 knapsack.
    We gotta make choices.
        a. include it
        b. don't include the element.

    */
    ll n, S=0;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
        cin >> a[i], S += a[i];
    if (S & 1)
        cout << "NO" << endl;
    else
        cout << (equalSumPartition(a, n, S / 2) ? "YES" : "NO") << endl;
    /*
    Sample Input:
    5
    2 3 5 7 8
    Output:
    NO

    Sample Input:
    5
    5 1 1 1 2
    Output: YES
    */

    return 0;
}