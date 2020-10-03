//Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

class Solution
{
public:
    int trap(vector<int>& height)
    {
        if (height.size() < 3) { return 0; }
        
        // Get the indices of two highest bars, sort them and put into top2bars
        array<vector<int>::iterator, 2> top2bars;
        top2bars[0] = max_element(height.begin(), height.end());
        int tmp = *(top2bars[0]);
        *(top2bars[0]) = INT_MIN;
        top2bars[1] = max_element(height.begin(), height.end());
		int top2bars_min = *(top2bars[1]); 
        *(top2bars[0]) = tmp;
        sort(top2bars.begin(), top2bars.end());
        
		// Calculate the amount of water between the two highest bars
        int output = 0;  // amount of trapped water
        for (auto it = top2bars[0] + 1; it < top2bars[1]; ++it)
        {
            output += top2bars_min - *it;
        }
        
		// Call recursively trap() on bars left and right to the top2bars and add to the output
        vector<int>&& left = {height.begin(), top2bars[0] + 1};
        vector<int>&& right = {top2bars[1], height.end()};
            
        return output + trap(left) + trap(right);
    }
};
