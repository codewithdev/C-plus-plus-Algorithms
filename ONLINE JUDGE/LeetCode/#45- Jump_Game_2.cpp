class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0;
        int n= nums.size();
        int maxjumps=0;
        int currjumps=0;
        for(int i=0;i<n-1;i++){ 
            maxjumps= max(maxjumps, i+nums[i]);
            if(i==currjumps)  
            {
                jumps++;
                currjumps= maxjumps;
            }
        }
        return jumps;
    }
};
