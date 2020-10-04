/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
class Solution
{
private:
    vector<int> temp, original;

public:
    Solution(vector<int> &nums)
    {
        temp = nums;
        original = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        return temp = original;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        for (int i = temp.size() - 1; i >= 0; i--)
        {
            int idx = rand() % (i + 1);
            swap(temp[i], temp[idx]);
        }
        return temp;
    }
};