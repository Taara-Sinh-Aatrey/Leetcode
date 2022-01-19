class Solution {
public:
    
    int rec(string &s, int i, int n, vector<int> &dp) {
        if (i < 0) {
            return 1;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        dp[i] = 0;
        int ch = s[i] - '0';
        if (ch >= 1) {
            dp[i] += rec(s, i - 1, n, dp);
        }
        if (i - 1 >= 0) {
            ch = (s[i - 1] - '0') * 10 + ch;
            if (ch >= 10 && ch <= 26) {
                dp[i] += rec(s, i - 2, n, dp);
            }
        }
        return dp[i];
    }
    
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return rec(s, n - 1, n, dp);
    }
};