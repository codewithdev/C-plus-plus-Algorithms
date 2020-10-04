class Solution {
public:
    int countPrimes(int n) {
      int ans=0;
      vector<long long int>arr;
      for(int i=0;i<n;i++)
      {
        arr.push_back(0);
      }
      for(int i=2;i<n;i++)
      {
        if(arr[i]==0)
        {
          for(int j=2;i*j<n;j++)
          {
          arr[i*j]=1;
          }
        }
      }
      for(int i=2;i<n;i++)
      {
        if(arr[i]==0)
        {
          ans++;
        }
      }
      return ans;
    }
};
