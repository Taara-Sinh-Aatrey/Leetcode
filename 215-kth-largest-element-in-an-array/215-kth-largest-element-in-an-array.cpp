class Solution {
public:
    
    int partition (vector<int>& nums, int lo, int hi) {
        
        int pivot = nums[hi];
        int i = lo;
        
        for (int j = lo; j < hi; j++)
            if (nums[j] <= pivot) 
                swap(nums[i++], nums[j]);
        
        swap(nums[i], nums[hi]);
        
        return i;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        
        int n = nums.size();
        k = n - k;
        int lo = 0, hi = n - 1;
        
        while (lo <= hi) {
            int p = partition(nums, lo, hi);
            if (p == k) 
                break;
            if (p < k) 
                lo = p + 1;
            else 
                hi = p - 1;
        }
        
        return nums[k];
    }
};