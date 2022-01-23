class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        const int dr[] = {-1, 0, 1, 0};
        const int dc[] = {0, -1, 0, 1};

        vector<vector<bool>> vis(n, vector<bool>(m));

        auto e = [&](int r, int c) {
            return 0 <= r && r < n && 0 <= c && c < m && grid[r][c] == '1' && !vis[r][c];  
        };
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '0' || vis[i][j])
                    continue;
                
                ans++;
                
                queue<pair<int, int>> q;
                q.emplace(i, j);
                vis[i][j] = true;
                
                while(!q.empty()) {
                    auto [r, c] = q.front();
                    q.pop();

                    for(int dir = 0; dir < 4; dir++) {
                        int nr = r + dr[dir];
                        int nc = c  + dc[dir];

                        if(e(nr, nc)) {
                            q.emplace(nr, nc);
                            vis[nr][nc] = true;
                        }
                    }
                }
            }
        }
        
        return ans;
        
    }
};