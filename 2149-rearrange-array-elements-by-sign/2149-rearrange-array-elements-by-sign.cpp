class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        vector<int> ans;
        while (ans.size() < n) {
            while (i < n && nums[i] <= 0)
                i++;
            while (j < n && nums[j] >= 0)
                j++;
            ans.emplace_back(nums[i++]);
            ans.emplace_back(nums[j++]);
        }
        return ans;
    }
};