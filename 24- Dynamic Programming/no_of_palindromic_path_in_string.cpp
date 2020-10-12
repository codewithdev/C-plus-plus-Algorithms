 #include<bits/stdc++.h>
 using namespace std;
 #define n 3
 #define m 4
int dp[n+1][m+1][n+1][m+1];
string s[n];
int path(int bi, int bj, int ci, int cj){
  if(bi>ci or bj>cj  or s[bi-1][bj-1]!= s[ci-1][cj-1]) return 0; 
  if(abs(bi-ci) + abs(bj-cj)==1) return 1;
  if(dp[bi][bj][ci][cj]!=-1) return dp[bi][bj][ci][cj];
  return dp[bi][bj][ci][cj]= path(bi+1,bj,ci-1,cj)+ path(bi+1,bj, ci,cj-1)
                              + path(bi,bj+1,ci-1,cj)+ path(bi, bj+1, ci,cj-1);

}                              

int main(){
s[0]= "aaab", s[1]= "baaa", s[2]= "abba";
memset(dp,-1, sizeof(dp));
path(1,1,n,m); 
cout<<dp[1][1][n][m]<<endl;

 return 0;
 }
