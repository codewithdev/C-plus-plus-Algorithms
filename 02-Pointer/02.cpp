#include <iostream>
using namespace std;
int main() {
    int x=10;
    cout<<&x<<endl;
    
    float y=20.3;
    cout<<&y<<endl;

    char ch= 'A';
    cout<<(void *)&ch<<endl;

    int *xptr;
    xptr= &x;
    cout<<xptr<<endl; //same result

   float *fptr;
   fptr= &y;
   cout<<fptr<<endl;
}
