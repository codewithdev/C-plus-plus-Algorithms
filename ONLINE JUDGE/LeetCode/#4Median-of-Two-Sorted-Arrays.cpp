class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>me;
        int m=nums1.size();
        int n=nums2.size();
        int i=0,j=0;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                me.push_back(nums1[i]);
                i++;
            }else{
                me.push_back(nums2[j]);
                j++;
            }
        }
            while(i<m){
                me.push_back(nums1[i]);
                i++;
            }
            while(j<n){
                me.push_back(nums2[j]);
                j++;
            }
        
        //for(int i=0;i<me.size();i++)cout<<me[i]<<"";
        int s=me.size();
        if(s%2!=0)  return me[s/2];
        else        return (me[s / 2] + me[s/ 2 - 1]) / 2.0;
    }
};
