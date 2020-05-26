#include<iostream>
using namespace std;
bool isOdd(int n){
    return (n&1);
}

//Get Bit by using AND operator 
//1. Create the mask for the given No. and for a ith place
//2. Perform '&' operator with the original no. of bit
//3. If that operation return '1' or '0'.
int getBit(int n, int i){
    int mask= (1<<i);
    int bit= (n&mask) > 0 ?1:0;
    return bit;
}
//Set Bit by using OR operator 
//1. Create a mask for the given No. and for the ith place
//2. Perform '|' operator with the original no. of bit
//3. If that operation return '1' or '0'
int setBit(int n, int i){
    int mask= (1<<i);
    int ans= n|mask;
    return ans;
}
int main()
{
    int n=5;
    int i;
    cin>>i;
    cout<<getBit(n,i)<<endl;
    cout<<isOdd(n)<<endl;
    cout<<"Ans= "<<setBit(n,i)<<endl;
}
