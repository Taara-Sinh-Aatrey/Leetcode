class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] != word[0]) {
                    continue;
                }
                
                vector<vector<bool>> act(n, vector<bool>(m));
                const int dr[] = {-1, 0, 1, 0};
                const int dc[] = {0, -1, 0, 1};
                
                function<bool(int, int, int)> dfs = [&] (int r, int c, int idx) -> bool {
                    if (board[r][c] != word[idx])
                        return false;
                    
                    if (idx + 1 == word.size())
                        return true;
                    
                    act[r][c] = true;
                    
                    for (int dir = 0; dir < 4; dir++) {
                        int nr = r + dr[dir];
                        int nc = c + dc[dir];
                        if (0 <= nr && nr < n && 0 <= nc && nc < m && !act[nr][nc]) {
                            if (dfs(nr, nc, idx + 1)) {
                                return true;
                            }
                        }
                    }
                    
                    act[r][c] = false;
                    return false;
                };
                
                if (dfs(i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};