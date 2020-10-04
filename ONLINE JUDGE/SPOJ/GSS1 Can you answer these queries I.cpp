#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f 

struct Node { 
    int maxPrefixSum; 
    int maxSuffixSum; 
    int totalSum; 
    int maxSubarraySum; 
   
    Node() 
    { 
        maxPrefixSum = maxSuffixSum = maxSubarraySum = -inf; 
        totalSum = -inf; 
    } 
};
Node merge(Node left, Node right)
{
    Node parent;
    parent.maxPrefixSum = max(left.maxPrefixSum,left.totalSum+right.maxPrefixSum);
    parent.maxSuffixSum = max(right.maxSuffixSum, right.totalSum+left.maxSuffixSum);
    parent.totalSum = left.totalSum+right.totalSum;
    parent.maxSubarraySum = max({left.maxSubarraySum,right.maxSubarraySum,left.maxSuffixSum+right.maxPrefixSum});
    return parent;
}
void construct_tree_util(Node*tree, int arr[], int low, int high, int pos)
{
    if(low==high)
    {
        tree[pos].maxPrefixSum=arr[low];
        tree[pos].maxSuffixSum=arr[low];
        tree[pos].totalSum=arr[low];
        tree[pos].maxSubarraySum=arr[low];
        return;
    }
    int mid = (low+high)/2;
    construct_tree_util(tree,arr,low,mid,2*pos);
    construct_tree_util(tree,arr, mid+1,high,2*pos+1);
    tree[pos] = merge(tree[2*pos],tree[2*pos+1]);
}
Node* construct_tree(int arr[],int n)
{
    
    int seglen;
    if((ceil(log2(n))==floor(log2(n))))
        seglen = n*2-1;
    else
        seglen = pow(2,(ceil(log2(n))))*2-1;
    Node* tree = new Node[seglen];
    construct_tree_util(tree,arr,0,n-1,1);
    return tree;
}

Node solveQueryUtil(Node*tree, int low, int high, int qlow, int qhigh, int pos)
{
    if(high<qlow||qhigh<low)
    {
        Node nullnode;
        return nullnode;
    }
    if(low>=qlow&&qhigh>=high)
        return tree[pos];
    int mid = (low + high)/2; 
    Node left = solveQueryUtil(tree, low, mid, qlow, qhigh, 2*pos); 
    Node right = solveQueryUtil(tree, mid + 1, high, qlow, qhigh, 2*pos + 1);  
    Node res = merge(left, right); 
    return res; 
}
int solveQuery(Node* tree, int low, int high, int n)
{
    Node res = solveQueryUtil(tree, 0, n - 1, low, high, 1); 
    return res.maxSubarraySum; 
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    Node* tree = construct_tree(arr,n);
    int m;
    cin>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        cout<<solveQuery(tree,x-1,y-1,n)<<endl;
    }
    return 0;
}