#include<bits/stdc++.h>
using namespace std;
#define ll long long
void deleteMiddleElement(stack<ll> &s, ll n) {
	if (s.empty())
		return;
	ll val = s.top();
	s.pop();
	deleteMiddleElement(s, n - 1);
	if (n != 0)  // if the element is middle element then do not add it
		s.push(val);
}
int main() {
	stack<ll> s;
	ll n; cin >> n;
	for (ll i = 0; i < n; i++) {
		ll x; cin >> x;
		s.push(x);
	}
	deleteMiddleElement(s, s.size() / 2);
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();

	}
}