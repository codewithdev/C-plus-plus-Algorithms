class Solution {
public:
    
    bool isValid(vector<vector<int>>& image, int row , int column)
    {
        if((row<0||row>=image.size()||column<0||column>=image[0].size()))
           return false;
          
         return true;
    }
           
    void call(vector<vector<int>>& image, int r, int c, int OldColour, int newColor )
           {
               if(!isValid(image,r,c))
                   return;
               
               if(image[r][c]!=OldColour)
                   return;
               
               //image[r][c]=newColor;
               floodFill(image, r,c,newColor);
           }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        
        if(!isValid(image,sr,sc))
            return image;
        
        
        int OldColour = image[sr][sc];
        
        if(OldColour==newColor)
            return image;
        
        image[sr][sc] = newColor;
        call(image, sr-1,sc,OldColour, newColor);
        call(image, sr+1,sc,OldColour, newColor);
      
        call(image, sr,sc-1,OldColour, newColor);
        call(image, sr,sc+1,OldColour, newColor);
        
        
        return image;
    }
};
