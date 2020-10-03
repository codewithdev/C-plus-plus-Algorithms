class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int minLeft = INT_MAX, maxRight = INT_MIN;
        for(int num : right) {
            minLeft = min(num, minLeft);
        }
        for(int num : left) {
            maxRight = max(maxRight, num);
        }
        return max(n - minLeft, maxRight);
    }
};
