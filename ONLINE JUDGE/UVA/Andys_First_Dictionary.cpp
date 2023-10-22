#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


int main()
{
	set <string> st;
    vector <string> V;
    string s, s2;

    
    while(cin >> s)
    {
        int sizeof_string = s.size();

        for(int i = 0; i < sizeof_string; i++)
        {
            if(s[i] >= 65 && s[i] <= 90)
            {
                s2 += (s[i] + 32);
            }
            else if(s[i] >= 97 && s[i] <= 122)
            {
            	s2 += s[i];
            }
            else
            {
            	
            	if(s2.size() != 0)
            	{
            		//cout << s2.size() << endl;
            		V.push_back(s2);
        			s2.clear();            		
            	}
            }
        }
        if(s2.size() != 0)
        {
            //cout << s2.size() << endl;
            V.push_back(s2);
        	s2.clear();            		
        }
    }


    sort(V.begin(), V.end());
    int sizeof_vector = V.size();
    for(int i = 0; i < sizeof_vector; i++)
    {
    	st.insert(V[i]);
    }
    
    set <string>::iterator it;
   
    for(it = st.begin(); it != st.end(); it++)
    {
    	cout << *it << endl;
    }
    
    return 0;
}
