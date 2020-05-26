#include<iostream>
using namespace std;
float squareroot(int n, int p){
    int s=0,e=n;
    float ans;
    int mid;
    while(s<=e){
        mid= (s+e)/2;
        if(mid*mid==n){
            ans=mid;
            break;
        }
        if(mid*mid<n){
            s=mid+1;
            ans= mid;
        }
        else{
            e=mid-1;
        }
    }
    //Fractional Part

    float inc= 0.1;
    for(int i=0;i<p;i++){
        while(ans*ans<=n){
            ans+=inc;
        }
        //ans*ans>n
        ans=ans-inc;
        inc= inc/10;
    }
    return ans;
}
int main(){
    cout<<squareroot(49,2)<<endl;
    cout<<squareroot(10,4)<<endl;
}