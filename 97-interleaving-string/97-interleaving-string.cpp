class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        
        if (n + m != s3.size())
            return false;
        
        vector<bool> dp(m + 1);
        
        for (int i = 0; i <= n; i++) {
            
            vector<bool> ndp(m + 1);
            
            for (int j = 0; j <= m; j++)
                ndp[j] = (j == 0 && i == 0) || (i > 0 && s3[i + j - 1] == s1[i - 1] && dp[j]) or (j > 0 && s3[i + j - 1] == s2[j - 1] && ndp[j - 1]);
            
            swap(dp, ndp);
            
        }
        
        return dp.back();
    }
};