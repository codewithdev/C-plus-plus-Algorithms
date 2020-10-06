#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        // Check for negative numbers
        if(n<=0)
            return 0;
        // We can check whether a number is a power of 2, by ANDing 
        // each bit of the number n with each corresponding bit of (n-1).
        // If the reusult of the operation is 0, the n is a power of 2, else it is not.
        // For e.g., let n = 8 = 0b1000
        // Hence, n-1 = 7 = 0b0111
        // ANDing each bit, we get 0b0000 = 0. Hence, 8 is a power of 2.
        // Hence, return !0 = 1.
        return !(n&(n-1));
    }
};

int main() {
    int num;
    bool res;
    Solution sol;
    cin>>num;
    res = sol.isPowerOfTwo(num);
    cout<<res<<endl;
    return 0;
}