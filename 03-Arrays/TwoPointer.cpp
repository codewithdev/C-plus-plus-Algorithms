/*
Two pointer algorithm
Problem : find wether a given number can be represented as sum of pair of elemnts in the given array
TimeComplexity = O(NlogN)
*/
#include<bits/stdc++.h> 
using namespace std;

int main()
{
    int a[]={-8,4,3,-2,-3,4,-6,8,21,15,8,0};
    int targetSum=19;
   
    sort(a,a+12);
     int i=0,j=11;
     bool flag=false;
    while(i<j)
    {
      if(a[i]+a[j]==targetSum)
      {
          flag=true;
          break;
      }
      if(a[i]+a[j]>targetSum)
      {
          j--;
      }
      else if(a[i]+a[j]<targetSum)
      {
          i++;
      }
    }
    if(flag)
    {
        cout<<"Yes\n";
        cout<<"Sum of elements at "<<i<<" and "<<j<<" result in "<<targetSum;
    }
    else{
        cout<<"No";
    }
}