class Solution {
  public:
    int longestPalindrome(string s) {
     map<char,int> check;
     int ans=0;
     for(int i=0;i<s.size();i++)
     {
       check[s[i]]++;
     }
     vector<int> temp;
     for(auto &x : check)
     {
       int val = x.second;
      
       if(val%2==0)
       {
         ans=ans+val;
       }
       else
       {
         temp.push_back(val);
       }
     }
     if(temp.size()!=0)
     {
         ans = ans+*max_element(temp.begin(),temp.end());
         temp.erase(max_element(temp.begin(),temp.end()));
         for(int i=0;i<temp.size();i++)
         {
             ans = ans + temp[i] - 1;
         }
     }
     return ans;
     }
};
