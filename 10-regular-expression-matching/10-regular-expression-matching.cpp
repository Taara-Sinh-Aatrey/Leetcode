class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        reverse(s.begin(), s.end());
        reverse(p.begin(), p.end());
        
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
        dp[0][0] = true;
        
        for (int i = 1; i <= n; i++) {
            if (p[i - 1] == '*')
                continue;
            for (int j = 0; j <= m; j++) {                
                // X*a == Ya
                if (i - 2 >= 0 && p[i - 2] == '*') {
                    dp[i][j] = dp[i - 2][j];
                }
                
                if (j == 0)
                    continue;
                
                if ((p[i - 1] == s[j - 1] || p[i - 1] == '.') && i - 2 >= 0 && p[i - 2] == '*') {
                    // X == Y
                    dp[i][j] = dp[i][j] | dp[i - 2][j - 1];
                    
                    // or X*a == Y
                    dp[i][j] = dp[i][j] | (dp[i][j - 1]);
                    
                }
                // Xa == Ya
                else if (p[i - 1] == s[j - 1] || p[i - 1] == '.') {
                    // X == Y
                    dp[i][j] = dp[i][j] | dp[i - 1][j - 1];
                }
            }
        }
        
        return dp[n][m];
    }
};