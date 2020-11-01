class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
       if(A.size()==1){
           return A[0];
       } 
    int sum=0;
        for(int i=0;i<A.size();i++){
            sum+=A[i];
        }
        int currMax=A[0],currMin=A[0],max_so_far=A[0],min_so_far=A[0];
        for(int i=1;i<A.size();i++){
            currMax= max(currMax+A[i],A[i]);
            max_so_far= max(max_so_far,currMax);
            currMin= min(currMin+A[i],A[i]);
            min_so_far= min(min_so_far,currMin);
        }
        if(min_so_far==sum){
            return max_so_far;
        }
        return max(max_so_far,sum-min_so_far);
    }
};
