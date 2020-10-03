class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      map<char, int> Mp;
        int start = -1;
        int len = 0;
        
        for(int i=0; i< s.size(); i++){
            if(Mp.count(s[i]) != 0)
            {
                start = max(start, Mp[s[i]]);
            }
            Mp[s[i]] = i;
            len = max(len, i-start);
        }
        return len;
    }
};
