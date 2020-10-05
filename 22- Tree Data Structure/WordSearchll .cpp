//Given a 2D board and a list of words from the dictionary, find all words in the board.
//Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" 
//cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.




#include <bits/stdc++.h> 
using namespace std; 
  
const int ALPHABET_SIZE = 26; 
  
// trie node 

class Solution {
public:
    vector<string>ret;
    struct TrieNode 
    { 
        struct TrieNode *children[ALPHABET_SIZE]; 
        bool isEndOfWord; 
    }; 

    struct TrieNode *getNode(void) 
    { 
        struct TrieNode *pNode =  new TrieNode; 

        pNode->isEndOfWord = false; 

        for (int i = 0; i < ALPHABET_SIZE; i++) 
            pNode->children[i] = NULL; 

        return pNode; 
    } 
    void insert(struct TrieNode *root, string key) 
    { 
        struct TrieNode *pCrawl = root; 

        for (int i = 0; i < key.length(); i++) 
        { 
            int index = key[i] - 'a'; 
            if (!pCrawl->children[index]) 
                pCrawl->children[index] = getNode(); 

            pCrawl = pCrawl->children[index]; 
        } 
        pCrawl->isEndOfWord = true; 
    } 
    int search(struct TrieNode *root, string key) 
    { 
        struct TrieNode *pCrawl = root; 

        for (int i = 0; i < key.length(); i++) 
        { 
            int index = key[i] - 'a'; 
            if (!pCrawl->children[index]) 
                return 0; 

            pCrawl = pCrawl->children[index]; 
        } 
        if(pCrawl->isEndOfWord==false && pCrawl!=NULL)
            return 1;
        if(pCrawl != NULL && pCrawl->isEndOfWord)
            return 2;
        return -1;
    } 
    void fn(struct TrieNode*root,vector<vector<char>>& board,string str,int i,int j)
    {
            char store =board[i][j];
            board[i][j]='0';
            int temp=0;
            if(i-1 >=0 && board[i-1][j]!='0')
            {   
                
                str.push_back(board[i-1][j]);
                backtrack(root,board,str,i-1,j);
                str.pop_back();
                board[i][j]=store;
            }
            if(j-1 >=0 && board[i][j-1]!='0')
            {
                str.push_back(board[i][j-1]);
                backtrack(root,board,str,i,j-1);
                str.pop_back();
                board[i][j]=store;
            }
            if(i+1 < board.size()  && board[i+1][j]!='0')
            {
                str.push_back(board[i+1][j]);
                backtrack(root,board,str,i+1,j);
                str.pop_back();
                board[i][j]=store;

            }
            if(j+1 <board[0].size() && board[i][j+1]!='0')
            {
                str.push_back(board[i][j+1]);
                backtrack(root,board,str,i,j+1);
                str.pop_back();
                board[i][j]=store;
                    
            }
            board[i][j]=store;
    }
    int backtrack(struct TrieNode*root,vector<vector<char>>& board,string str,int i,int j)
    {
        if(search(root,str)==0)
        {
            return 0;
        }
        else
        {
            if(search(root,str)==2)
                {
                    ret.push_back(str);
                }
            char store =board[i][j];
            board[i][j]='0';
            int temp=0;
            if(i-1 >=0 && board[i-1][j]!='0')
            {   
                 board[i][j]='0';
                str.push_back(board[i-1][j]);
                temp=backtrack(root,board,str,i-1,j);
                str.pop_back();
                    board[i][j]=store;
            }
            if(j-1 >=0 && board[i][j-1]!='0')
            {
                 board[i][j]='0';
                str.push_back(board[i][j-1]);
                temp=backtrack(root,board,str,i,j-1);
                str.pop_back();
                     board[i][j]=store;
            }
            if(i+1 < board.size()  && board[i+1][j]!='0')
            {
                 board[i][j]='0';
                str.push_back(board[i+1][j]);
                temp=backtrack(root,board,str,i+1,j);
                str.pop_back();
                    board[i][j]=store;
            }
            if(j+1 <board[0].size() && board[i][j+1]!='0')
            {
                 board[i][j]='0';
                str.push_back(board[i][j+1]);
                temp=backtrack(root,board,str,i,j+1);
                str.pop_back();
                board[i][j]=store;
                    
            }
            board[i][j]=store;
            return temp;
            
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    int n = words.size(); 
    if(words.size()==0)
    {
        vector<string>r;
        return r;
    }
    struct TrieNode *root = getNode(); 
    vector<vector<char>>copy=board;
    // Construct trie 
    for (int i = 0; i < n; i++) 
        insert(root, words[i]);    
    for(int i=0;i<board.size();i++)
        for(int j=0;j<board[0].size();j++)
        {
            copy=board;
            string str(1,board[i][j]);   
            backtrack(root,copy,str,i,j);
           
        }
    vector<string>::iterator ip; 
  if(ret.size()==0)
      return ret;
    sort(ret.begin(),ret.end());
        vector<string>final;
    for (int i=1;i<ret.size();i++) { 
        if(ret[i-1]!=ret[i])
            final.push_back(ret[i-1]);
    }
        final.push_back(ret[ret.size()-1]);
        return final;
    }
};
