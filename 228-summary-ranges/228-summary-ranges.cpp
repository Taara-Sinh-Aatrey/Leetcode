class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        
        int n = nums.size();
        for (int i = 0, j; i < n; i = j) {
            j = i + 1;
            while (j < n && nums[j] == nums[j - 1] + 1) j++;
            
            ans.emplace_back(to_string(nums[i]) + (j - 1 == i ? "" : "->" + to_string(nums[j - 1])));
        }
        
        return ans;
    }
};