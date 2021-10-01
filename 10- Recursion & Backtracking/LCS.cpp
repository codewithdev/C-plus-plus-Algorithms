#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll LCS(string X, string Y, ll n, ll m) {
    /*
    Base case:
    If either one of the two strings becomes null string, we cannot choose
    more from it.
    So return 0.
    */
    if (n == 0 || m == 0)
        return 0LL;
    /*
    Choice Diagram:
    A. If the n-1th and m-1th character of both strings is equal, we select it and recur
    for n-1 and m-1
    B. If they are not equal, we have two choices.
        1. Recur for n-1,m
        2. Recur for n,m-1
        We have to find the LCS, so we will choose the max among the two cases.
    */
    if (X[n - 1] == Y[m - 1])
        return LCS(X, Y, n - 1, m - 1) + 1LL;
    else {
        return max(LCS(X, Y, n - 1, m), LCS(X, Y, n, m - 1));
    }
}
int main() {
   
    /*
    LONGEST COMMON SUBSEQUENCE LENGTH
    Given two string X and Y, find the length of LCS between them.
    */
    string X, Y; cin >> X >> Y;
    ll n = X.size(), m = Y.size();
    cout << LCS(X, Y, n, m) << endl;

    /*
    Sample Input:
    AGGTAB
    GXTXAYB
    Output: 
    4
    Sample Input:
    ABCDGH
    AEDFHR
    Output:
    3
    */

    return 0;
}
