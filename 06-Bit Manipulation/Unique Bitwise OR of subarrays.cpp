// This algorithm finds unique Bitwise OR of
// all the subarrays of an array.
// The Time Complexity might look like
// its O(n^2), but upon taking a closer look 
// at algorithm, it comes out to be of the 
// order of O(n)
#include <bits/stdc++.h>
using namespace std;

int subarrayBitwiseORs(vector<int>& A) {
    unordered_set<int> st;
    int n = A.size(), chk = 0, curr;
    for(int i = n - 1; i >= 0; i--) {
        curr = A[i];
        st.insert(curr);
        chk = 0;
        for(int j = i + 1; j < n && chk != curr; j++) {
            curr |= A[j];
            chk |= A[j];
            st.insert(curr);
        }
    }
    return st.size();
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << subarrayBitwiseORs(arr) << endl;
    return 0;
}