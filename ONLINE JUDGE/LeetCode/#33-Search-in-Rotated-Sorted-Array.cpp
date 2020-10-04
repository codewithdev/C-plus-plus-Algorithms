class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int n=nums.size();
        int index=-1, low=0, high=n-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(mid>0 && nums[mid]<nums[mid-1]) 
            {
                index = mid-1;
                break;
            }
            if(mid<n-1 && nums[mid]>nums[mid+1])
            {
                index = mid;
                break;
            }
            if(nums[mid]>nums[high]) low = mid+1;
            else high = mid-1;
        }
        low = 0, high = index;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) high = mid-1;
            else low = mid+1;
        }
        low = index+1, high = n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) high = mid-1;
            else low = mid+1;
        }
        return -1;
    }
};
