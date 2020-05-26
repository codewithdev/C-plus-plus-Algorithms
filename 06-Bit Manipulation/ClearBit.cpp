#include<iostream>
using namespace std;

// 1. Create a mask and Negate it to clear the particular bit
// 2. AND Operation on the original bit
void clearBit(int &n, int i){
    int mask= ~(1<<i);
    n=n&mask;

}
int main()
{
    int n=5;
    int i;
    cin>>i;
    clearBit(n,i);
    cout<<n<<endl;
}