class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() <= 2)
            return 0;
        int n = nums.size();
        int diff = nums[1] - nums[0], len = 2, ans = 0;
        
        for (int i = 2; i < n; i++) {
            int cur_diff = nums[i] - nums[i - 1];
            
            if (cur_diff == diff) {
                len++;
                ans += len - 2;
            }
            else {
                diff = cur_diff;
                len = 2;
            }
        }
        
        return ans;
    }
};