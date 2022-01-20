class Solution {
public:
    int rob(vector<int>& a) {
        int n = a.size();
        const int inf = 1e9L + 5;
        vector<int> dp(n, -inf);

        for (int i = 0; i < n; i++) {

            int prev = i - 2 >= 0 ? dp[i - 2] : -inf;

            dp[i] = max({a[i] + prev, a[i], prev});

            if (i > 0)
                dp[i] = max(dp[i], dp[i - 1]);
        }

        return dp.back();
    }
};