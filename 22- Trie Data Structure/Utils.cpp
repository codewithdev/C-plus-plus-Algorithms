#include<bits/stdc++.h>
using namespace std;


vector<string> get_array_from_file(string src){

    fstream file(src);

    string word;
    vector<string> words;

    if(!file){
        cerr << "\nCan't Open File"<<src<< " Some Error Occures\n";
        return words;
    }

   while(!file.eof()){
  
      getline(file,word);

      if(word.size()) words.push_back(word);
      
      word = "\0";
   }
   return words;
} 


int kmp_algo(string P,string T){
    
    string s=P + "#" + T;
 
     vector<int> pi(s.size());


      for(int i=1;i<(int)s.size();i++){    //prefix function
       	   int j= pi[i-1];
       	   while(j>0 and s[i]!=s[j])
       	      j=pi[j-1];
       	   if(s[i]==s[j])
       	    j++;
       	   pi[i]=j; 
       }
       
    for(int i=P.size();i<(int)s.size();i++){
    	if(pi[i]==(int)P.size()){
    		return 1;
    	}
    }
    return -1;
}



// GLOBAL Search

vector<string> search(vector<string> v, string pat)
{

    vector<string> results;

    auto start = chrono::high_resolution_clock::now();

    for (auto text : v)
    {
        if (kmp_algo(pat, text) != -1)
        {  
            results.push_back(text);
        }
    }

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);

    cerr << "\033[32m\n"
         << results.size() << " results in " << double(duration.count() / double(1000000)) << " ms.\033[0m\n\n";

    return results;
}