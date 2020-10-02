/*
Sliding Window Technique
Problem : Find maximum sum of subarray if size k
TimeComplexity = O(N)
*/
#include<bits/stdc++.h> 
using namespace std;

int main()
{
    int a[]={-8,4,3,-2,-3,4,8,21,-6,15,8,0};
   int k=4;
   int curSum=0,maxSum=0;
   for(int i=0;i<k;i++)
   {
       curSum+=a[i];
   }
   maxSum=curSum;
   
   for(int i=k;i<12;i++)
   {
      curSum+=a[i]-a[i-k];
      maxSum=max(curSum,maxSum);
      
   }
   cout<<maxSum;
}