class Solution {
public:
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int L = 0, R = n - 1;
        
        if (nums.front() > nums.back()) {
            int lo = 0, hi = n - 1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (nums[mid] >= nums[0]) {
                    lo = mid + 1;
                }
                else {
                    hi = mid - 1;
                }
            }
            // assert(lo == hi);
            if (target <= nums.back()) {
                L = lo, R = n - 1;
            }
            else {
                L = 0, R = hi - 1;
            }
        }
        auto it = lower_bound(nums.begin() + L, nums.begin() + R + 1, target);
        return it != nums.end() && *it == target ? it - nums.begin() : -1;
    }
};