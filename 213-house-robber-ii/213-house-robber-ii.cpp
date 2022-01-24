class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        
        int n = nums.size(), ans = 0;
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++) {
            dp[i] = dp[i - 1];
            dp[i] = max(dp[i], (i - 2 >= 0 ? dp[i - 2] : 0) + nums[i]);
            ans = max(ans, dp[i]);
        }
        
        vector<int> dp2(n, 0);
        for (int i = 0; i < n - 1; i++) {
            if (i - 1 >= 0)
                dp2[i] = dp2[i - 1];
            dp2[i] = max(dp2[i], (i - 2 >= 0 ? dp2[i - 2] : 0) + nums[i]);
            ans = max(ans, dp2[i]);
        }
        
        return ans;
    }
};