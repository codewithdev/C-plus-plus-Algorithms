class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        vector<int> n=nums;
        int t=target,ans;
        for(int i=0;i<n.size();i++)
        {
            if(n.at(i)==t)
            {
                ans=i;
                break;
            }
            if(n.at(i)>t)
            {
                ans=i;
                break;
            }
        }
        return ans;
    }
};
