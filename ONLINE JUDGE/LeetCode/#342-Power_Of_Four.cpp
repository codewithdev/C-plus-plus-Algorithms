class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num >= 0)
            return ((num & (num-1))==0 && (num & 0b1010101010101010101010101010101) != 0);
        // 1010101010101010101010101010101 is a mask to check odd powers of 2.
        // Even powers of 2 = powers of 4
        else
            return false;
    }
};