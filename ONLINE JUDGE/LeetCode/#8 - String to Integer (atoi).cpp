class Solution {
public:
    int myAtoi(string str) {
        
        string to_conv;
        for(int i=0; i<str.size() ; i++)
        {
            if(str[i]>='a'&&str[i]<='z')
                break;
            
            to_conv.push_back(str[i]);
        }
        
        if(to_conv.size()==0)
            return 0;
        
        long x=0;
        int sign = 1,i=0;
        
        while(to_conv[i]==' ')
            i++;
        
        if(to_conv[i]=='-')
        {
            sign = -1;
            i++;
        }
        else if(to_conv[i]=='+')
        {
            sign = 1;
            i++;
        }
        
        while(to_conv[i]=='0')
            i++;
        
        while(str[i]!=' '&&to_conv[i]>='0'&&to_conv[i]<='9'&&i<to_conv.length()) 
        {   
            if(x<=INT_MAX&&x>=INT_MIN) 
            {   
			    x = x * 10 + to_conv[i] - '0';     
		    }
            
            if(x>=INT_MAX)
            {
                
                if(sign == -1)
                {
                    if(x*sign<=INT_MIN)
                        return INT_MIN;
                }
                else
                    return INT_MAX;
            }
            i++;   
        }
        
        x*=sign;

        return x;
    }
};
