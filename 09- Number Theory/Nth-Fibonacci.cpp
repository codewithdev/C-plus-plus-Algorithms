// This program calculates Nth- Fibonacci Number in Log(n) time

#include <iostream>
#include <vector>

using namespace std;

void multi(vector<vector<int64_t>> &v, vector<vector<int64_t>> m){
    int64_t val_1 = (v[0][0] * m[0][0]) + (v[0][1] * m[1][0]);
    int64_t val_2 = (v[0][0] * m[0][1]) + (v[0][1] * m[1][1]);
    int64_t val_3 = (v[1][0] * m[0][0]) + (v[1][1] * m[1][0]);
    int64_t val_4 = (v[1][0] * m[0][1]) + (v[1][1] * m[1][1]);
     
    v[0][0] = val_1;
    v[0][1] = val_2;
    v[1][0] = val_3;
    v[1][1] = val_4;

}

void powerCal(vector<vector<int64_t>> &v, int n){
    if(n == 1 || n == 0){
        return;
    }
    
    // Calculating V ^ (n/2)
    powerCal(v, n/2);

    // Multiplying matrices to get result
    multi(v, v);
    
    // In case n is odd
    if(n & 1){
        vector<vector<int64_t>> m{{1,1},{1,0}};
        multi(v, m);  
    }


}

int64_t fibonacciNumber(int n){
    vector<vector<int64_t>> v{{1,1}, {1,0}};
    if(n == 0){
        return 0;
    }
    else if(n == 1 || n == 2){
        return 1;
    }

    powerCal(v, n-1);
    return v[0][0];    
}

// Driver Function
int main(){
    int n;     
    cout << "Enter N : ";
    cin >> n;

    cout << "Nth Fibonacci Number : " << fibonacciNumber(n);

    return 0;
}
