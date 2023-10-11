#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector <int> v;
    int n, a;


    while(cin >> n)
    {
        if(n == 0)
        {
            break;
        }
        while(n--)
        {
            cin >> a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());
        int sv = v.size();

        for(int i = 0; i < sv; i++)
        {
            cout << v[i];
            if(i < sv-1)
            {
                cout << " ";
            }
        }
        cout << endl;
        v.clear();
    }

    return 0;
}
