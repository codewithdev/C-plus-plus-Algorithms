#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

void insert(vector<ll> &v, ll value) {
    if (v.size() == 0 || v[v.size() - 1] <= value) {
        v.pb(value);
        return;
    }
    ll ele = v[v.size() - 1];
    v.pop_back();
    insert(v, value);
    v.pb(ele);
}
void sortRecursively(vector<ll> &v) {
    if (v.size() == 1) {
        return;
    }
    ll val = v[v.size() - 1];
    v.pop_back();
    sortRecursively(v);
    insert(v, val);
}
int main() {
  
    /*
    Thought Process:
    Firstly decide a clear task which you want your recursive function to do.
    It will do that only.
    Do not change the task it does in between the question. 
    It should be fixed.
    sortRecursively function takes a vector removes the last elemnt and sorts the remaining part.
    You do not need to worry how, it will. It is really MAGICAL.
    After removing the last element we need to insert it in the correct place.
    So we define an insert function for that.
    
    */
    ll n; cin >> n;
    vector<ll> v;
    for(ll i = 0; i < n; i++) {
        ll x; cin >> x;
        v.pb(x);
    }
    sortRecursively(v);
    cout << v.size() << endl;
    for (auto i : v)
        cout << i << " ";
    cout << endl;

    return 0;
}

