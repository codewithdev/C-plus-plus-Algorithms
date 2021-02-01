/*Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many 
days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].*/


```cpp

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n= T.size();
        stack<int>s;
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
        while(!s.empty() and T[s.top()]<T[i]){
            int j= s.top();
            s.pop();
            ans[j]= i-j;
        }
        s.push(i);
    }
    return ans;
    }

};
```
