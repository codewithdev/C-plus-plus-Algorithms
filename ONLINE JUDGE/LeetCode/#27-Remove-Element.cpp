/*This is an iterative soloution.
   check if the next item in the array is the searched number, if it is we delete and return the size of the new array.
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
         if(nums.size() == 0){
            return 0;
        }

        for(int i=0;i<nums.size();i++){
            if(nums[i] == val){
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        return nums.size(); 
    }
};