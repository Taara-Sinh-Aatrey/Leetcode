class Solution {
public:
    
    bool solve(vector<vector<char>>& board, vector<vector<bool>> &row, vector<vector<bool>> &col, vector<vector<vector<bool>>> &box, int cellNumber) {
        if (cellNumber >= 81)
            return true;
        
        int r = cellNumber / 9, c = cellNumber % 9;
        
        if (board[r][c] != '.')
            return solve(board, row, col, box, cellNumber + 1);
        
        for (int x = 1; x < 10; x++) {
            
            if (row[r][x] || col[c][x] || box[r / 3][c / 3][x])
                continue;
            
            row[r][x] = col[c][x] = box[r / 3][c / 3][x] = true;
            board[r][c] = '0' + x;
            
            if (solve(board, row, col, box, cellNumber + 1))
                return true;
            
            board[r][c] = '.';
            row[r][x] = col[c][x] = box[r / 3][c / 3][x] = false;
        }
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        
        vector<vector<bool>> row(9, vector<bool>(10));
        vector<vector<bool>> col(9, vector<bool>(10));
        vector<vector<vector<bool>>> box(3, vector<vector<bool>>(3, vector<bool>(10)));
        
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                
                if (board[r][c] == '.')
                    continue;
                
                int x = board[r][c] - '0';
                row[r][x] = col[c][x] = box[r / 3][c / 3][x] = true;
            }
        }
        
        solve(board, row, col, box, 0);
    }
};