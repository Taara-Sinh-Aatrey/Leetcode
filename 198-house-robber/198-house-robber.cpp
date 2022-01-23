class Solution {
public:
    int rob(vector<int>& a) {
        int n = a.size();
        const int inf = 1e9L + 5;
        
        vector<int> dp(2, -inf);
        
        for (int i = 0; i < n; i++)
            dp = {dp[1], max({dp[1], a[i] + dp[0], a[i], dp[0]})};

        return dp.back();
    }
};