#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    map <string, string> mp;
    string s1, s2, s3;
    int n, m;

    cin >> n;
    cin.ignore();
    while(n--)
    {
        getline(cin, s1);
        getline(cin, s2);
        mp.insert(make_pair(s1, s2));
    }
    cin >> m;
    cin.ignore();
    while(m--)
    {
        getline(cin, s1);
        cout << mp[s1] << endl;
    }
    return 0;
}
