#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        // Check for positive numbers.
        if(num >= 0)
            return ((num & (num-1))==0 && (num & 0b1010101010101010101010101010101) != 0);
        // We can check whether a number is a power of 2, by ANDing 
        // each bit of the number n with each corresponding bit of (n-1).
        // If the reusult of the operation is 0, the n is a power of 2, else it is not.
        // For e.g., let n = 8 = 0b1000
        // Hence, n-1 = 7 = 0b0111
        // ANDing each bit, we get 0b0000 = 0. Hence, 8 is a power of 2.
        // 1010101010101010101010101010101 is a mask to check odd powers of 2, i.e., 1's in odd position.
        // If the ANDing operation of the number and the mask returns 0, then it is an odd power.
        // Even powers of 2 = powers of 4. If it is an odd power, we reject that answer.
        // For e.g., 0b1000 AND 0b0101 = 0 => the condition (num & mask) becomes false and 0 is returned.
        else
            return false;
    }
};

int main() {
    int num;
    bool res;
    Solution sol;
    cin>>num;
    res = sol.isPowerOfFour(num);
    cout<<res<<endl;
    return 0;
}