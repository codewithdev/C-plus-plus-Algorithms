#include<bits/stdc++.h>
using namespace std;
//This function below is the solution to the problem
int maximumProduct(vector<int>& nums) {
        int p1,p2;
        int max1,max2,max3,small1,small2;
        max1=max2=max3=-1001;
         small1=small2=1001;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=max3){
                max1=max2;
                max2=max3;
                max3=nums[i];
            }else if(nums[i]>=max2){
                max1=max2;
                max2=nums[i];
            }else if(nums[i]>=max1){
                max1=nums[i];
            }
            
            if(nums[i]<=small1){
                small2=small1;
                small1=nums[i];
            }else if(nums[i]<=small2){
                small2=nums[i];
            }
        }
        p1=max1*max2*max3;
        p2 = small1*small2*max3;
        return max(p1,p2);
}
//Driver Code
int main(){
    vector <int> nums = {1,2,3};
    cout<<maximumProduct(nums);
return 0;
}