class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        
        int start = 0, cur = 0, ans = n + 1;
        for (int end = 0; end < n; end++) {
            // let's include end in the solution set
            cur += nums[end];
            
            // remove the unnecessary elements from the start
            while (start < end && cur - nums[start] >= target) {
                cur -= nums[start++];
            }
            
            if (cur >= target) {
                ans = min(ans, end - start + 1);
            }
        }
        
        return ans <= n ? ans : 0;
    }
};