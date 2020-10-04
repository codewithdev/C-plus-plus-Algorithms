class Solution {
  public:
    vector<vector<int>> threeSum(vector<int>& A) {
        if(A.size()<3)
        {
            vector<vector<int>> emp;
            return emp;
        }
      set<vector<int>> ans;
      sort(A.begin(),A.end());
      for(int i=0;i<A.size()-2;i++)
      {
        if(i==0||A[i]>A[i-1])
        {
        int left=i+1,right=A.size()-1;
        
        while(left<right)
        {
          if(A[left]+A[right]>(-A[i]))
          {
              right--;
          }
          else if(A[left]+A[right]<(-A[i]))
          {
              left++;
          }
          
          if((right!=left)&&(A[left]+A[right]==(-A[i])))
          {
          vector<int> temp;
          temp.push_back(A[i]);
          temp.push_back(A[left]);
          temp.push_back(A[right]);
          ans.insert(temp);
          left++;
          right--;
          }
        }
        
        }
      }
      vector<vector<int>> ans1;
      for(auto itr=ans.begin();itr!=ans.end();itr++)
      {
        ans1.push_back(*(itr));
      }
      return ans1;
    }
};
