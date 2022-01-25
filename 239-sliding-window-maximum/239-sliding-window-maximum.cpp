class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> ms;
        vector<int> ans;
        
        for (int i = 0; i < nums.size(); i++) {
            if (i >= k)
                ms.erase(ms.find(nums[i - k]));
            
            ms.insert(nums[i]);
            
            if (i >= k - 1)
                ans.emplace_back(*ms.rbegin());
        }
        
        return ans;
    }
};