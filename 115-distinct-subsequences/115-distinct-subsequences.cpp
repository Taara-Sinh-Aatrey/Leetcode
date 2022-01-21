class Solution {
public:
    int numDistinct(string s, string t) {
        
        int n = s.size(), m = t.size();
        vector<unsigned long long> dp(m + 1);
        dp[0] = 1;
        
        // const long long inf = 1e18;
        
        for (int i = 1; i <= n; i++) {
            for (int j = m; j > 0; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                    // if (dp[j] > inf) dp[j] = inf;
                }
            }
        }
        
        return dp[m];
    }
};