class Solution {
public:
    int minSpaceWastedKResizing(vector<int>& nums, int K) {
        K++;
        const int inf = 1e9;
        int n = nums.size();
        
        vector<vector<int>> dp(n, vector<int>(K + 1, inf));
        for (int i = 0; i < n; i++) {
            int mx = 0, sum = 0;
            
            for (int j = i; j >= 0; j--) {
                mx = max(mx, nums[j]);
                sum += nums[j];
                for (int k = 1; k <= K; k++) {
                    dp[i][k] = min(dp[i][k], (j > 0 ? dp[j - 1][k - 1] : 0) + mx * (i - j + 1) - sum);
                }
            }
        }
        
        return dp[n - 1][K];
    }
};