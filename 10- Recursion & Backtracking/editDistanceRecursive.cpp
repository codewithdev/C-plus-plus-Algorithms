#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll editDistance(string X, string Y, ll n, ll m) {
    /*
    The base conditions:
    If either of the strings is empty you need the corresponding lengths to 
    make them same
    If the characters are same do nothing and go for a smaller input
    If not, we need to do something which costs 1 and them we choose the least cost amongst
    insert, replace and remove.
    Replace-> call for(n-1,m-1)
    Insert-> call for(n,m-1)
    Remove->call for(n-1,m)

    */
    if (n == 0)
        return m;
    if (m == 0)
        return n;
    if (X[n - 1] == Y[m - 1])
        return editDistance(X, Y, n - 1, m - 1);
    else
        return 1 + min(editDistance(X, Y, n - 1, m - 1), min(editDistance(X, Y, n - 1, m), editDistance(X, Y, n, m - 1)));
}
int main() {

    /*
    Edit Distance.
    Convert String X to string Y by doing insert, replace and remove.
    All three are of the same cost.
    Find the minimum cost of conversion
    */
    string X, Y; cin >> X >> Y;
    cout << editDistance(X, Y, X.size(), Y.size());

    return 0;
}

