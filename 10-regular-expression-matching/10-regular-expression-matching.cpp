class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
        dp[0][0] = true;
        
        for (int i = 1; i <= n; i++) {
            
            if (p[i - 1] == '*')
                continue;
            
            for (int j = 0; j <= m; j++) {  
                // Xa* == X
                int pv = i - 1;
                if (pv > 0 && p[pv - 1] == '*')
                    pv--;
                
                if (i + 1 <= n && p[i] == '*') {
                    dp[i][j] = dp[pv][j];
                }
                if (j == 0)
                    continue;
                
                // Xa* = Ya
                if ((p[i - 1] == s[j - 1] || p[i - 1] == '.') && i + 1 <= n && p[i] == '*') {
                    // X == Y
                    dp[i][j] = dp[i][j] | dp[pv][j - 1];
                    
                    // or Xa* == Y
                    dp[i][j] = dp[i][j] | (dp[i][j - 1]);
                    
                }
                // Xa == Ya
                else if (p[i - 1] == s[j - 1] || p[i - 1] == '.') {
                    // X == Y
                    dp[i][j] = dp[i][j] | dp[pv][j - 1];
                }
            }
        }
        
        return dp[n - (p[n - 1] == '*')][m];
    }
};