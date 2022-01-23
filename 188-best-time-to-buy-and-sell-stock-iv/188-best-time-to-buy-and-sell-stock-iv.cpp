class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        const int inf = 1e9;
        
        k *= 2;
        int n = prices.size();
        
        vector<int> dp(k + 1, -inf);
        dp[0] = 0;
        
        for (auto &x : prices) {
            for (int i = k; i > 0; i--)
                dp[i] = max(dp[i], dp[i - 1] + (i % 2 == 1 ? -1 : 1) * x);
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};