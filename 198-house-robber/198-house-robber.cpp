class Solution {
public:
    int rob(vector<int>& a) {
        int n = a.size();
        const int inf = 1e9L + 5;
        vector<int> dp(2, -inf);
    
        for (int i = 0; i < n; i++) {

            int prev = dp[0];

            int cur = max({a[i] + prev, a[i], prev});

            cur = max(cur, dp[1]);

            dp = {dp[1], cur};
        }

        return dp.back();
    }
};