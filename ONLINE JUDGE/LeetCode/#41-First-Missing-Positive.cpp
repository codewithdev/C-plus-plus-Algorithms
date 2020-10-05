class Solution {
public:
    int firstMissingPositive(vector<int>& a) {
        
        int n=a.size();
        set<int>temp;
        
        for(int i=0;i<n;i++){
            if(a[i]>0) temp.insert(a[i]);
        }
        int ans=1;
        for(auto i:temp){
            if(ans!=i)  return ans;
            else        ans++;
        }
        return ans;
        
    }
};
