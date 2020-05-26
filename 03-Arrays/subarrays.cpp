#include <iostream>
using namespace std;
int main() {
       int n;
       cin>>n;
       int a[1000];
       for(int i=0;i<n;i++)
       {
           cin>>a[i];
       }

       //Generating Subarrays
       for(int i=0;i<n;i++)
       {
           for(int j=i;j<n;j++)
           {
               for(int k=i;k<=j;k++)
               {
                   //Printing the subarrays
                   cout<<a[k]<<",";
               }
               cout<<endl;
           }
       }




}
