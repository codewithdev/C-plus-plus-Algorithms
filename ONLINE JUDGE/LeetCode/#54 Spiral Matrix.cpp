
class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      vector<int> ans;
      if(matrix.size()==0)
      {
          return ans;
      }
      int top = 0 , right = matrix[0].size()-1, bottom = matrix.size()-1, left = 0;
      while(top<=bottom&&left<=right)
      {
        //top layer
        for(int i=left;i<=right;i++)
        {
          ans.push_back(matrix[top][i]);
        }
        top++;
        
        //right layer
        for(int i=top;i<=bottom;i++)
        {
          ans.push_back(matrix[i][right]);
        }
        right--;
        if(top>bottom||left>right)
        {
            break;
        }
        //bottom layer
        for(int i=right;i>=left;i--)
        {
          ans.push_back(matrix[bottom][i]);
        }
        bottom--;
        
        //left layer
        for(int i=bottom;i>=top;i--)
        {
          ans.push_back(matrix[i][left]);
        }
        left++;
      }
    return ans;
    }
};
