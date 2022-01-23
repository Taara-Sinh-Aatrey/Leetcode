class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        while (start + 1 < n && nums[start] == nums[start + 1])
            start++;
        start++;
        if (start >= n)
            return nums[0];
        
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
        return nums[(peak + 1) % n];
    }
};