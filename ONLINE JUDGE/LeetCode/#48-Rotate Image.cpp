class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size()/2,i=0,sz=matrix.size()-1;
      for(int i=0;i<n;i++)
      {
        for(int j=i;j<sz-i;j++)
        {
          int temp1 = matrix[i][j];
          int temp2 = matrix[j][sz-i];
          int temp3 = matrix[sz-i][sz-j];
          int temp4 = matrix[sz-j][i];
          matrix[i][j] = temp4;
          matrix[j][sz-i] = temp1;
          matrix[sz-i][sz-j] = temp2;
          matrix[sz-j][i] = temp3;
        }
      }
    
    }
};
