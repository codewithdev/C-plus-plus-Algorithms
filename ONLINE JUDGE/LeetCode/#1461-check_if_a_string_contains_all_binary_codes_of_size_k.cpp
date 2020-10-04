class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int need = 1<<k;
        vector<bool> got(need);
        int allOne = need - 1;
        int hashVal = 0;
        for(int i = 0 ; i < s.length() ; i++) {
            //calculate hash for s.substr(i-k+1,i+1)
            hashVal = ((hashVal << 1) & allOne) | (s[i] - '0');
            if(i >= k - 1 && !got[hashVal]){
                got[hashVal] = true;
                need--;
                if (need == 0){
                    return true;
                }
            }
        }
        return false;
    }
};
