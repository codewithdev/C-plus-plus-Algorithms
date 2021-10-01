#include<bits/stdc++.h>
using namespace std;
#define ll long long

void insert(stack<ll> &s, ll value) {
    if (s.size() == 0 || s.top() <= value) {
        s.push(value);
        return;
    }
    ll ele = s.top();
    s.pop();
    insert(s, value);
    s.push(ele);
}
void sortRecursively(stack<ll> &s) {
    if (s.size() == 1) {
        return;
    }
    ll val = s.top();
    s.pop();
    sortRecursively(s);
    insert(s, val);
}
int main() {

    ll n; cin >> n;
    stack<ll> s;
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        s.push(x);
    }
    sortRecursively(s);
    cout << s.size() << endl;
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;


    return 0;
}

