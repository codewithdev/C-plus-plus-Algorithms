#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool subsetSum(ll a[], ll n, ll S)
{
    /*
    Base case:
    If n==0 && S==0 we can have an empty subset
    If n==0 && S!=0 we cannot have empty subset
    If n!=0 && S==0 we can choose an empty subset
    Think of the smallest possible input which keeps on changing in the 
    revursive code.
    */
    if (n == 0 && S == 0)
        return 1;
    else if (n == 0 && S != 0)
        return 0;
    else if (n != 0 && S == 0)
        return 1;

    /*
    The choice diagram.
    Start from the back.
    We used max in the 0-1 knapsack, here we use || because if either of the two sums 
    is possible we should get a 1. Similar to the boolean max thing(is || only).

    */
    if (a[n - 1] <= S) {
        return subsetSum(a, n - 1, S - a[n - 1]) || subsetSum(a, n - 1, S);
    }
    else {
        return subsetSum(a, n - 1, S);
    }
}
int main() {

    /*
    Given Input:
    n denotes the number of elements in the array
    a[i] is the ith element of the array
    S is the target sum.
    To find:
    Return True if any subset with the given sum exists else return false.

    Interpretations:
    Problem is similar to 0-1 knapsack.
    We gotta make choices.
        a. include it
        b. don't include the element.

    */
    ll n, S;
    cin >> n >> S;
    ll a[n];
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    cout << (subsetSum(a, n, S) ? "YES" : "NO") << endl;
    /*
    Sample Input:
    5 1
    2 3 5 7 8
    Output:
    NO

    Sample Input:
    5 11
    2 3 5 7 8
    Output: YES
    */
    return 0;
}
