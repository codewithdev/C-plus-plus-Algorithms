class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res = 0;
        unordered_set<char> J_set(J.begin(), J.end()); 
        //Start iterator, end iterator is passed to the constructor to make the set
        for(int i=0; i<S.size(); i++)
        {
            if(J_set.find(S[i]) != J_set.end())
                res++;
        }
        return res;
    }
};