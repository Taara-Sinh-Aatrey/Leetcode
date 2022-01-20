class Solution {
public:
    
    bool solve(vector<vector<char>>& board, vector<vector<bool>> &row, vector<vector<bool>> &col, vector<vector<vector<bool>>> &box, int i, int j) {
        if (i == 9 && j == 0) {
            return true;
        }
        int ni = i, nj = j + 1;
        if (j == 9) {
            ni++;
            nj = 0;
        }
        if (board[i][j] != '.') {
            return solve(board, row, col, box, ni, nj);
        }
        for (int x = 1; x < 10; x++) {
            if (row[i][x] || col[j][x] || box[i / 3][j / 3][x]) {
                continue;
            }
            row[i][x] = col[j][x] = box[i / 3][j / 3][x] = true;
            board[i][j] = '0' + x;
            if (solve(board, row, col, box, ni, nj)) {
                return true;
            }
            board[i][j] = '.';
            row[i][x] = col[j][x] = box[i / 3][j / 3][x] = false;
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(10));
        vector<vector<bool>> col(9, vector<bool>(10));
        vector<vector<vector<bool>>> box(3, vector<vector<bool>>(3, vector<bool>(10)));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                int x = board[i][j] - '0';
                row[i][x] = col[j][x] = box[i / 3][j / 3][x] = true;
            }
        }
        solve(board, row, col, box, 0, 0);
    }
};