#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector <long long> v;
    int N, i = 1, n;

    while(cin >> N)
    {
        v.push_back(N);
        sort(v.begin(), v.end());
        if(i%2 != 0)
        {
            n = i/2;
            cout << v[n] << endl;
        }
        else
        {
            cout << (v[n]+v[n+1])/2 << endl;
        }
        i++;
    }
    return 0;
}
