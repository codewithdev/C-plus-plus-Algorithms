class Solution {
public:
    
    void colourit(vector<vector<char>> & grid,int r, int c, char colour)
    {
        if(r<0||r>=grid.size()||c<0||c>=grid[0].size())
            return;
        
        if(grid[r][c]=='1')
        {
            grid[r][c] = colour;
            colourit(grid,r+1,c,colour);
            colourit(grid,r-1,c,colour);
            colourit(grid,r,c+1,colour);
            colourit(grid,r,c-1,colour);     
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
      
        char ch = 'a';
        int ctr = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    colourit(grid,i,j,ch);
                    ch++;
                    ctr++;
                }   
            }
        }
        
       // int d = ch-'a';
        return ctr;
        
    }
};
