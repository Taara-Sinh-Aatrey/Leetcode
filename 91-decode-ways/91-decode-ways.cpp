class Solution {
public:
    
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            // i is the end of the current susbtring
            if (s[i] != '0') {
                dp[i] += (i - 1 >= 0 ? dp[i - 1] : 1);
            }
            if (i > 0 && s[i - 1] != '0') {
                int code = (s[i - 1] - '0') * 10 + s[i] - '0';
                if (code <= 26) {
                    dp[i] += (i - 2 >= 0 ? dp[i - 2] : 1);
                }
            }
        }
        return dp.back();
    }
};