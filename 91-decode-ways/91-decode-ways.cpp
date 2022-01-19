class Solution {
public:
    
    int rec(string &s, int i, int n, vector<int> &dp) {
        if (i >= n) {
            return 1;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        dp[i] = 0;
        int ch = s[i] - '0';
        if (ch >= 1) {
            dp[i] += rec(s, i + 1, n, dp);
        }
        if (i + 1 < n) {
            ch = ch * 10 + s[i + 1] - '0';
            if (ch >= 10 && ch <= 26) {
                dp[i] += rec(s, i + 2, n, dp);
            }
        }
        return dp[i];
    }
    
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return rec(s, 0, n, dp);
    }
};