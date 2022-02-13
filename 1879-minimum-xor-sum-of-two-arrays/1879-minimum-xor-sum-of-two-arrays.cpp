class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        const int inf = 1e9;
        int n = nums1.size();
        vector<int> dp(1 << n, inf);
        dp[0] = 0;
        
        for (int mask = 0; mask < 1 << n; mask++) {
            int cnt = __builtin_popcount(mask);
            for (int i = 0; i < n; i++) {
                if (~mask >> i & 1) {
                    int new_mask = mask | (1 << i);
                    dp[new_mask] = min(dp[new_mask], dp[mask] + (nums1[i] ^ nums2[cnt]));
                }
            }
        }
        
        return dp[(1 << n) - 1];
    }
};