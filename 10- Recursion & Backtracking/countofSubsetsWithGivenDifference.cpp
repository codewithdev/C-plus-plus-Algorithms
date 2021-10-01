#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll findCountofSubsets(ll a[], ll n, ll S) {
    if (n == 0 && S == 0)
        return 1;
    if (n == 0 && S != 0)
        return 0;
    if (n != 0 && S == 0)
        return 1;
    if (a[n - 1] <= S) {
        return findCountofSubsets(a, n - 1, S) + findCountofSubsets(a, n - 1, S - a[n - 1]);
    }
    else return findCountofSubsets(a, n - 1, S);
}
int main() {
   
    /*
    Given n as the size of array
    a[i] is the ith element of the array
    S is the requeired absolute difference between the two partitions of the array
    To find:
    Count the number of valid pairs of subsets such that the given difference
    is obtained
    */
    ll n, S; cin >> n >> S;
    ll a[n];
    ll sum = 0;
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if ((sum + S) & 1)
        cout << 0 << endl;
    else
        /*
        Why (sum+S)/2;
        sum(subset1)-sum(subset2)=difference(S);
        sum(subset1)+sub(subset2)=sumofArray(sum);
        Add these two
        sum(subset1)=(S+sum)/2
        */
        cout << findCountofSubsets(a, n, (sum + S) / 2) << endl;

    return 0;
}


