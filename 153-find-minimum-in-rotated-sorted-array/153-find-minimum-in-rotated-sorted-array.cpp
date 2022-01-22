class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        
        if (n == 1 || nums.front() < nums.back()) {
            return nums.front();
        }
        
        int low = 1, high = n - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (nums[mid] <= nums[0]) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return nums[low];
    }
};