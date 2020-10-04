class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int,int> vals;

        for(int i=0;i<nums.size();i++)
        {
            if(vals.find(target - nums[i])!=vals.end()&&vals[target - nums[i]]!=i)
                return {i,vals[target - nums[i]]};
            else
                vals[nums[i]] = i;
                
        }
        
        return {};
    }
};
