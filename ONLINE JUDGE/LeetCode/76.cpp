class Solution {
public:    
    string minWindow(string s, string t) {
        unordered_map<char, int> table;
        
        // initialize frequency table for t
        for(char c : t){
            table[c]++;
        }
        
        // initialize sliding window
        int begin = 0, end = 0;
        int counter = table.size();
        int len = INT_MAX;
        
        string ans = "";
        
        // start sliding window
        while(end < s.length()){
            char endchar = s[end];
            
            // if current char found in table, decrement count
            if(table.find(endchar) != table.end()){
                table[endchar]--;
                if(table[endchar] == 0) counter--;
            }
            
            end++;
            

            while(counter == 0){
                // store new answer if smaller than previously best
                if(end-begin < len){
                    len = end - begin;
                    ans = s.substr(begin, end - begin); 
                }
                
 
                int startchar = s[begin];
                
                if(table.count(startchar) == 1){
                   table[startchar]++;
                   if(table[startchar] > 0) counter++; 
                }
                
                begin++;
            }
        }
        
        return ans;
    }
};
