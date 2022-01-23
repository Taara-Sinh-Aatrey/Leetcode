class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        
        int start = 0, end = n - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if ((mid == 0 || nums[mid - 1] < nums[mid]) && (mid == n - 1 || nums[mid] > nums[mid + 1])) {
                return mid;
            }
            else if (mid == 0) {
                start = mid + 1;
            }
            else if (mid == n - 1) {
                end = mid - 1;
            }
            else if (nums[mid] <= nums[mid + 1]) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        assert(false);
    }
};