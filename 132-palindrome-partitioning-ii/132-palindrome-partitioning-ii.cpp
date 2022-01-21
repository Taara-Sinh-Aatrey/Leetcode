class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, n);
        dp[0] = 0;
        
        vector<vector<bool>> palindrome(n + 1, vector<bool>(n + 1));
        for (int i = n; i >= 1; i--) {
            for (int j = i; j <= n; j++) {
                palindrome[i][j] = s[i - 1] == s[j - 1] && (i + 1 > j - 1 || palindrome[i + 1][j - 1]);
            }
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                if (palindrome[i][j])
                    dp[j] = min(dp[j], dp[i - 1] + 1);
            }
        }
        
        return dp[n] - 1;
    }
};