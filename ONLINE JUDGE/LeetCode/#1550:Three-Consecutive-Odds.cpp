#include<bits/stdc++.h>
#include<string.h>
#define ll long long int
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define endl "\n"
using namespace std;
bool threeConsecutiveOdds(vector<int>& arr) {
        bool flag=false;
        for(int i=1;i<arr.size()-1;i++){
            if(arr[i]&1 and arr[i-1]&1 and arr[i+1]&1){
                flag=true;
                break;
            }
        }
        return flag;
}
void solve(){
    //input
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
		cin>>arr[i];
    }
    cout<<threeConsecutiveOdds(arr);
}
int main()
{
    fio;
    solve();
}
 
