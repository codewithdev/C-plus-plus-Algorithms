#include <iostream>
using namespace std;

int main() {
	// your code goes here
	
	long long number;
	cin >> number;
    for(int i = 0; i < number; i++){
        long long  a;
        cin >> a;
        if(a < 4){
            cout << -1 << endl;
        }
        else if( a == 4){
            cout << 2 << " " << 4 << " " << 1  << " " << 3 ;
        }
        else{
        for(long long i = 1; i <= a; i = i+2){
            cout << i << " " ;
        }
        for(long long i = 2; i <= a; i = i+2){
            cout << i << " ";
        }
        }
      cout << endl;  
    }
	
	
	
	
	
	return 0;
}
