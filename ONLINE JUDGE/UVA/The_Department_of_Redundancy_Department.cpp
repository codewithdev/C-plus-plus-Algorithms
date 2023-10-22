#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> v;
    vector <int> :: iterator it;
    int i = 0, n, m, ss, c = 0;

    //getting input
    while(cin >> n)
    {
        v.push_back(n);
    }
    ss = v.size();
    //input done

    while(v.size() > 0)
    {
        m = v[0];
        cout << m << " ";
        for(it = v.begin(); it != v.end(); it++)
        {
            if(m == *it)
            {
                c++;
                v.erase(it);
                it--;
            }
        }
        cout << c << endl;
        c = 0;
    }

    return 0;
}
