#include<iostream>
#include<string>
using namespace std;

int main()
{
    while(true)
    {
        string s;
        cin>>s;
        if((s[0])=='0')
            break;
        long long int memo[s.length()]={0};
        memo[0]=1;
        for(int i=1;i<s.length();i++)
        {
            if(s[i]!='0')
                memo[i]=memo[i-1];
            int num = ((s[i]-'0')+10*((s[i-1]-'0')));
            if(num>=10&&num<=26&&i>1)
                memo[i]+=memo[i-2];
            else if(num>=10&&num<=26&&i==1)
                memo[1]+=1;
        }
        cout<<memo[s.length()-1]<<endl;
    }
    return 0;
}