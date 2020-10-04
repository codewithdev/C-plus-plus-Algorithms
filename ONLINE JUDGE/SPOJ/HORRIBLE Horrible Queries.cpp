#include<bits/stdc++.h>
using namespace std;

long long int tree[400001]={0};
long long int lazy[400001]={0};

void updateRange(long long int ss, long long int se, long long int us, long long int ue, long long int diff, long long int si)
{
    if(lazy[si]!=0)
    {
        tree[si] += (se-ss+1)*lazy[si];
        if(se!=ss)
        {
            lazy[2*si+1]+=lazy[si];
            lazy[2*si+2]+=lazy[si];
        }
        lazy[si]=0;
    }
    if(ss>se||ss>ue||se<us)
        return;
    if(us<=ss&&ue>=se)
    {
        tree[si]+= (se-ss+1)*diff;
        if(ss!=se)
        {
            lazy[2*si+1] += diff;
            lazy[2*si+2] += diff; 
        }
        return;
    }
    long long int mid = ss + (se-ss)/2;
    updateRange(ss,mid,us,ue,diff,2*si+1);
    updateRange(mid+1,se,us,ue,diff,2*si+2);
    tree[si] = tree[2*si+1]+tree[2*si+2];
}
long long int getSum(long long int ss, long long int se, long long int qs, long long int qe, long long int si)
{
    if(lazy[si]!=0)
    {
        tree[si] += (se-ss+1)*lazy[si];
        if(se!=ss)
        {
            lazy[2*si+1]+=lazy[si];
            lazy[2*si+2]+=lazy[si];
        }
        lazy[si]=0;
    }
    if(ss>se||ss>qe||se<qs)
        return 0;
    if(qs<=ss&&qe>=se)
        return tree[si];
    long long int mid = ss + (se-ss)/2;
    return getSum(ss,mid,qs,qe,2*si+1)+getSum(mid+1,se,qs,qe,2*si+2);
}
void constructTreeUtil(long long int arr[], long long int ss, long long int se, long long int si)
{
    if(ss>se)
        return;
    if(ss==se)
    {
        tree[si]=arr[ss];
        return;
    }
    long long int mid = ss + (se-ss)/2;
    constructTreeUtil(arr,ss,mid,2*si+1);
    constructTreeUtil(arr,mid+1,se,2*si+2);
    tree[si] = tree[2*si+1]+tree[2*si+2];
}
void constructTree(long long int arr[], long long int n)
{
    constructTreeUtil(arr,0,n-1,0);
}
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n,c;
        cin>>n>>c;
        long long int arr[n] = {0};
        memset(tree,0,sizeof(tree));
        memset(lazy,0,sizeof(tree));
        constructTree(arr,n);
        for(long long int i=0;i<c;i++)
        {
            long long int flag,p,q,v;
            cin>>flag;
            if(flag==0)
            {
                cin>>p>>q>>v;
                updateRange(0,n-1,p-1,q-1,v,0);
            }
            else
            {
                cin>>p>>q;
                cout<<getSum(0,n-1,p-1,q-1,0)<<endl;
            }   
        }
    }
    return 0;
}