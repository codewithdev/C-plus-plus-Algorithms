#include<bits/stdc++.h>
using namespace std;
int main(){
   int n;
   cin>>n;
   priority_queue<int, std::vector<int>,greater<int>>pq;
   for(int i=0;i<n;i++){
   	int no;cin>>no;
   	pq.push(no);
   }
   while(!pq.empty()){
   	cout<<pq.top()<<" ";
   	pq.pop();
   }
}