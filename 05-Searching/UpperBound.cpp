/*
Upper Bound

*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={2,6,8,12,15,29,35,51,51,167,232,303,489,500};
    int target=51;

    int l=0,r=14;
    while(l<r)
    {
        int mid=l+(r-l)/2;
        if(target>=arr[mid])
        {
          
           l=mid+1;
        }
        else{
             r=mid;
        }
    }
    cout<<l;

}