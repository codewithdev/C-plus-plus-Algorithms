/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
*/
//implementation through stack
class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        int f = 1;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '{' || s[i] == '[' || s[i] == '(')
            {   
                stk.push(s[i]);
            }
            else
            {
                if(stk.empty())
                {
                    f = 0;
                    break;
                }
                char open_bracket = stk.top();
                if((s[i] == (open_bracket + 1)) || (s[i] == (open_bracket + 2)))
                {
                    stk.pop();
                }
                else{
                    f = 0;
                    break;
                }
            }
        }
        if(f == 1 && stk.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
