/*Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
*/


```cpp

//Solution by codewithdev
class Solution {
public:
    static bool compare(pair<char,int>&a, pair<char,int>&b){
        return a.second>b.second;
    }
    string frequencySort(string s) {
    unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        string ans="";
        vector<pair<char,int>>vec;
        for(auto x:mp){
            vec.push_back(make_pair(x.first,x.second));
        }
        sort(vec.begin(),vec.end(),compare);
        for(auto x:vec){
            while(x.second>0){
                ans+=x.first;
                x.second--;
            }
        }
        return ans;
        
    }
};

```
