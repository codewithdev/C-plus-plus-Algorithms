class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string> > ret;
        map<vector<int>,vector<string>> group;
        
        for(int i = 0; i<strs.size();i++)
        {
            vector<int> word(26,0);
            for(int j = 0; j<strs[i].size();j++)
            {
                word[strs[i][j] - 'a']++;
            }
            group[word].push_back(strs[i]);
        }
        
        for(auto itr : group)
            ret.push_back(itr.second);
        
        return ret;
  
    }
};
