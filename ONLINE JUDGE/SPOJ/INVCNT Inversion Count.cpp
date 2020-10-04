#include<iostream>
#include<vector>
using namespace std;
typedef long long int LL;

LL merge(vector<LL> &arr, vector<LL> &temp, LL l, LL m, LL r)
{
    LL i=l,j=m,k=l,inv=0;
    //vector<LL> temp(arr.size());
    while(i<m&&j<=r)
    {
        if(arr[i]<arr[j])
            temp[k++]=arr[i++];
        else if(arr[i]==arr[j])
        {
            temp[k++]=arr[i++];
            j++;
        }
        else
        {
            temp[k++]=arr[j++];
            inv += (m-i);
        }

    }
    while(i<m)
        temp[k++]=arr[i++];
    while(j<=r)
        temp[k++]=arr[j++];
    for(LL p=l;p<=r;p++)
        arr[p]=temp[p];
    return inv;
}
LL mergesort(vector<LL> &arr,vector<LL> &temp, LL l, LL r)
{
    LL inv=0;
    if(l<r)
    {
        LL mid = (l+r)/2;
        inv += mergesort(arr,temp,l,mid);
        inv += mergesort(arr,temp,mid+1,r);
        inv += merge(arr,temp,l,mid+1,r);
    }
    return inv;
}
LL _mergesort(vector<LL> arr,LL n)
{
    vector<LL> temp(n);
    return mergesort(arr,temp,0,n-1);
}
int main()
{
    LL t;
    cin>>t;
    while(t--)
    {
        LL n;
        cin>>n;
        vector<LL> arr(n);
        for(LL i=0;i<n;i++)
            cin>>arr[i];
        LL inv = _mergesort(arr,n);
        cout<<inv<<endl;
    }
    return 0;
}