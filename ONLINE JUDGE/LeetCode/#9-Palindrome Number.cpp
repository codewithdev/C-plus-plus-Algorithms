class Solution {
public:
    
    bool isPalindrome(int x) {
        if(x==0)
            return true;
        if(x<0)
        return false;
      int size = log10(x)+1;
      for(int i=0;i<size/2;i++)
      {
        int a=pow(10,size-1-(i*2)),b=10;
        if(x/a!=x%b)
        {
          cout<<x<<" ";
          return false;
        }
        else
        {
          x=x%a;
          x=x/b;
        }
      }
      return true;
    }
};
