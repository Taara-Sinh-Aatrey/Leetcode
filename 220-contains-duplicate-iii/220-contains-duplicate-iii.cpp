class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        multiset<int> ms;
        
        for (int i = 0; i < n; i++) {
            if (i > k)
                ms.erase(ms.find(nums[i - k - 1]));
            
            auto it = ms.emplace(nums[i]);
            
            if (next(it) != ms.end() && *next(it) <= (long long) nums[i] + t)
                return true;
            
            if (it != ms.begin() && *prev(it) >= (long long) nums[i] - t)
                return true;
        }
        
        return false;
    }
};