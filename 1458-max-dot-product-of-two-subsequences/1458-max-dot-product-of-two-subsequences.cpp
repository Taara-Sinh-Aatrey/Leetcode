class Solution {
public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        const int inf = 1e9 + 5;
        int n = a.size(), m = b.size();
        // dp[i][j] is the max dot product of two equal subseq of a and b when we have considered i elements of a and j elements of b
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -inf));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // a[i] * b[j]
                dp[i][j] = max({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1] + a[i - 1] * b[j - 1], 0 + a[i - 1] * b[j - 1]});
            }
        }
        
        return dp[n][m];
    }
};