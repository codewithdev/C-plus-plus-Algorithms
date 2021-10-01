//Problem Name: Grumpy Bookstore owner
//Problem Link: https://leetcode.com/problems/grumpy-bookstore-owner/


//Code:

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
         int satisfied=0;
         int n= customers.size();
         for(int i=0;i<n;i++){
            if(grumpy[i]==0)
                satisfied+= customers[i];
          }
        int additionalsatisfied= 0; 
        int left=0;
        int right= minutes;
        for(int i=0;i<minutes;i++){
            if(grumpy[i]==1)
            {
                additionalsatisfied+= customers[i];
            }
        }
        int maxx= additionalsatisfied;
        while(right<n){
            if(grumpy[right]==1){
                additionalsatisfied+= customers[right]; /* If the satisfied customer found, then include in the given window or minute.*/
            }
            if(grumpy[left]==1){
                additionalsatisfied-= customers[left]; /*If the unsatisfied customers found, then exclude from the window*/
            }
            maxx= max(maxx, additionalsatisfied);
         left++;
        right++;
            }
        
        return satisfied+maxx;
    }
};
