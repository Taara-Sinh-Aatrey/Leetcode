class Solution {
public:
    bool isScramble(string s, string t) {
        int n = s.size();
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n + 1)));
        
        // dp[i][j][l] represents if s[i...i+l-1] is scrambled string of t[j...j+l-1]
        // s = "great", t = "rgeat"
        // dp[0][1][2] = "gr" is scrambled of "ge" or not
        
        for (int l = 1; l <= n; l++) {
            for (int i = 0; i + l <= n; i++) {
                for (int j = 0; j + l <= n; j++) {
                    // dp[i][j][l]
                    if (l == 1) {
                        dp[i][j][l] = s[i] == t[j];
                    }
                    else {
                        // l -> x l-x
                        for (int x = 1; x < l; x++) {
                            int y = l - x;
                            
                            dp[i][j][l] = dp[i][j][l] | (dp[i][j][x] && dp[i + x][j + x][y]);
                            dp[i][j][l] = dp[i][j][l] | (dp[i][j + y][x] && dp[i + x][j][y]);
                        }
                    }
                    
                }
            }   
        }
        
        return dp[0][0][n];

    }
};