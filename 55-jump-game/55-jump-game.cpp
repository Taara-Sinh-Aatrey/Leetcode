class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int max_range = 0;
        for (int i = 0; i < n; i++) {
            // i is less than or equal to max_range, so we can go there
            if (i <= max_range) {
                // if we have reached here, we might as well jump
                max_range = max(max_range, i + nums[i]);
            }
            else {
                return false;
            }
        }
        return true;
    }
};