/*This is an iterative soloution.
    we go over each individual number and see if the following number in the array is identical or not.
    if it is we use the erase function of vectors.
    we return the size of the the array at the end.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        if(nums.size() == 1){
            return 1;
        }
        for(int i=0;i<nums.size()-1;i++){
            if(nums.at(i) == nums.at(i+1)){
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        return nums.size(); 
    }
};