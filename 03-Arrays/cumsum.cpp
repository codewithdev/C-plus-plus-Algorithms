#include <iostream>
using namespace std;
int main() {
     int n;cin>>n;
     int a[1000];
     int cumsum[1000]={0};
     int currentsum=0;
     int maxsum=0;
     int left=-1;
     int right=-1;
     cin>>a[0];
     cumsum[0]= a[0];
     for(int i=1;i<n;i++)
     {
         cin>>a[i];
         cumsum[i]= cumsum[i-1]+a[i];
        
     }
     for(int i=0;i<n;i++)
     {
         for(int j=i;j<n;j++)
         {
             currentsum=0;
             currentsum= cumsum[j]- cumsum[i-1];
             if(currentsum>maxsum)
             {
                maxsum= currentsum;
                left=i;
                right=j;
             }
         }
     }
    cout<<"Maximum sum="<<maxsum<<endl;

    //print the Subarray

    for(int k=left;k<=right;k++)
    {
        cout<<a[k]<<",";
    }
      
      


}
