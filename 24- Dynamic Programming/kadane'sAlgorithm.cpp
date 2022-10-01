#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:

    long long maxSubarraySum(int arr[], int n){
        
        // if single element array
        if(n == 1){
        return arr[0];
        }
        
        long long sum = 0;
        long long maxs = arr[0];
        
        
        for(int i=0;i<n;i++)
        {
            //current element + sum 
            sum += arr[i];
            
            //if maxs <  sum 
            maxs = max(maxs,sum);
            
            //if answer < 0
            sum = (sum < 0) ? 0 : sum;
        }
        return maxs;
    }
};



int main()
{
    int t,n;
    
    cin>>t; //input test cases
    while(t--) //while test cases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
