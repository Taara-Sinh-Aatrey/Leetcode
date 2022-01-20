class Solution {
public:
    bool isScramble(string s, string t) {
        int n = s.size();
        vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(n, vector<bool>(n)));
        
        for (int l = 1; l <= n; l++) {
            for (int i = 0; i + l <= n; i++) {
                for (int j = 0; j + l <= n; j++) {
                    if (l == 1) {
                        dp[l][i][j] = s[i] == t[j];
                    }
                    else {
                        for (int l2 = 1; l2 < l; l2++) {
                            dp[l][i][j] = dp[l][i][j] | (dp[l2][i][j] && dp[l - l2][i + l2][j + l2]);
                            dp[l][i][j] = dp[l][i][j] | (dp[l2][i][j + l - l2] && dp[l - l2][i + l2][j]);
                        }
                    }
                }
            }
        }
        
        return dp[n][0][0];
    }
};