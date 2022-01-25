class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (matrix[i][j] == '0')
                    continue;
                
                dp[i][j] = 1 + min({dp[i + 1][j], dp[i][j + 1], dp[i + 1][j + 1]});
                ans = max(ans, dp[i][j]);
            }
        }
        
        return ans * ans;
    }
};