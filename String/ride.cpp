/*ID : idevpra1
PROG: ride
LANG: C++*/

#include<bits/stdc++.h> 
using namespace std; 
int main() 
{
  
  // freopen("ride.in","r",stdin);
  // freopen("ride.out","w",stdout);
  string s1,s2;
  int p1,p2;
  cin>>s1>>s2;
  for(int i=1;i<s1.length();i++) p1*=s1[i]-'A'+1;
  for(int i=1;i<s2.length();i++) p2*=s2[i]-'A'+1;
    p1%=47;
    p2%=47;
  if(p1==p2) cout<<"Equal"<<endl;
  else cout<<"Not Equual"<<endl;
}
  



 
 
