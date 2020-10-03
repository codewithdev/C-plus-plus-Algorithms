class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<array<bool,9>> rows(9);
        vector<array<bool,9>> cols(9);
        vector<array<bool,9>> squares(9);
                    
        for (int y = 0; y < 9 ; ++y)  {
            for (int x = 0; x < 9; ++x) {
                if (board[y][x] == '.') continue;
                
                const int current = board[y][x] - '1';
                
                if (rows[y][current]) {
                   return false; 
                } else {
                   rows[y][current] = 1;
                }
                if (cols[x][current]) {
                   return false; 
                } else {
                   cols[x][current] = 1 ;
                }
                
                const int sq_index = (y / 3) * 3 + x / 3;
                if (squares[sq_index][current]) {
                    return false;     
                } else {
                    squares[sq_index][current] = 1 ;
                }
            }
        }
        return true;
    }
};
