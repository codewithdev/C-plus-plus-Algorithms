#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare (int a, int b)   //Function is used to Implement the sorting in reverse order
{
    return a>b;
}
int main()
{
    int n;cin>>n;
    vector<int> v;
    v.reserve(100);                       //Reserve at least memory. After that vector will again inititalize the memory 
    for(int i=0;i<n;i++)
    {
        int temp;cin>>temp;
        v.push_back(temp);    // It inserts the element in the array 
    }
    sort(v.begin(), v.end(), compare);
    v.pop_back();      //It removes the last element from the array
    v.capacity();         // Function is used to demonstrate the size of the vector
    for(int i=0;i<v.size();i++)
    {
      cout<<v[i]<<" ";  
    }
    for(vector<int>::iterator it= v.begin();it!=v.end();it++ )
    {
    	cout<<' '<<*it;
	}
}
