class Solution {
public:
    
    int dfs(int i,int j,int n, int m, vector <vector <char>>& g){
        //Conditions to check for
        if(i<0||j<0||i>n-1||j>m-1||g[i][j]=='0') return 0;
        
        //value of g here as 0 so no further dfs calls are made 
        g[i][j]='0';
        
        //DFS calls in all four directions
        dfs(i-1,j,n,m,g);
        dfs(i+1,j,n,m,g);
        dfs(i,j+1,n,m,g);
        dfs(i,j-1,n,m,g);
        
        return 1;
    }
    
    int numIslands(vector<vector<char>>& grid) {

        if(grid.empty()==true) return 0;
        
        //Answer Variable
        int ans=0;
        int n=grid.size(); //rows
        int m=grid[0].size(); //columns

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){ //we check for 1 in grid and call dfs on the matrix
                    ans+=dfs(i,j,n,m,grid);
                }
            }
        }
        
        return ans;
    }
};