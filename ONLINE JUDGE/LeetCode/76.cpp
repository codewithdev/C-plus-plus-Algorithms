#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;

void init()
{
}

void solve()
{
    string s;
    string t;
    cin >> s >> t;
    int flag = 0;
    int lenT = t.length();
    int lenC = t.length();
    int startIndex = 0;
    int lastIndex = 0;
    map<char, int> freq;
    int f = INT_MAX;
    int ansIndex = 0;
    map<char, int> isPresent;
    for (int i = 0; i < lenT; i++)
    {
        isPresent[t[i]]++;
    }
    if (s.find(t) != string::npos)
    {
        cout << t<<endl;
        flag = 1;
    }
   
    else if (!flag)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (isPresent[s[i]])
            {
                if (!freq[s[i]])
                {
                    --lenC;
                    freq[s[i]]=i;
                    if (lenC == lenT - 1)
                    {
                        startIndex = i;
                    }
                    else if (lenC == 0)
                    {

                        if (i - startIndex < f)
                        {
                            f = i - startIndex;
                            ansIndex = startIndex;
                        }
                        lenC = lenT-1;
                        startIndex = i;
                        for (int i = 0; i < lenT; i++)
                        {
                            freq[t[i]] = 0;
                        }
                        freq[t[i]]=1;
                    }
                }
            }
        }
        for (int i = ansIndex; i < ansIndex + f + 1; i++)
        {
            cout << s[i];
            flag = 1;
        }
        cout << endl;
    }
    else if (!flag)
    {
        cout << "" << endl;
    }
}

int main()
{
    init();
    int t;
    cin >> t;
    while (t)
    {
        solve();
        --t;
    }

    return 0;
}