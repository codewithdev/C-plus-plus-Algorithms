/*

First Missing Positive (link - https://leetcode.com/problems/first-missing-positive/description/)

Description

Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

 

Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.

Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.

Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1



*/


#include<bits/stdc++.h>
using namespace std;

// Function to find first positive integer missing from the given list
int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    for(int i=0;i<n;i++) {
        // If number does not point to its location, then swap it with its proper location
        // Given that it is within the constraints of the length of list and destination does not
        // contain proper integer as well
        if(i+1 != nums[i]) {
            if(nums[i] <= n and nums[i] >= 1 && nums[i] != nums[nums[i]-1]) swap(nums[i], nums[nums[i]-1]),i--;
        }
    }

    // Check which location is not containing its respective integer
    for(int i=0;i<n;i++) {
        if(i+1 != nums[i]) return i+1;
    }

    // Return length of list + 1 in case the list contains every positive integer till then
    return n+1;
}

// Driver function
int main() {
    int n;
    cout<<"Enter size of list: ";
    cin>>n;
    cout<<"Enter Numbers:\n";
    vector<int> nums;
    for(int i=0;i<n;i++) {
        int t;
        cin>>t;
        nums.push_back(t);
    }

    cout<<"First Missing Positive: "<<firstMissingPositive(nums)<<"\n";
    return 0;
}