class Solution {
public:
    
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        while (start + 1 < n && nums[start] == nums[start + 1])
            start++;
        start++;
        if (start >= n)
            return nums[0] == target;
        
        int L = start, R = n - 1;
        int peak = start - 1;
        while (L <= R) {
            int mid = (L + R) / 2;
            if (nums[mid] > nums.front()) {
                peak = mid;
                L = mid + 1;
            }
            else {
                R = mid - 1;
            }
        }

        if (target >= nums.front()) {
            L = 0, R = peak;
        }
        else {
            L = peak + 1, R = n - 1;
        }
        
        return binary_search(nums.begin() + L, nums.begin() + R + 1, target);
    }
};