class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> nums(n, 1);
        
        int i2 = 0, i3 = 0, i5 = 0;
        
        for (int i = 1; i < n;) {
            nums[i] = min({nums[i2] * 2, nums[i3] * 3, nums[i5] * 5});
            
            if (nums[i2] * 2 == nums[i])
                i2++;
            else if (nums[i3] * 3 == nums[i])
                i3++;
            else
                i5++;
            
            i += nums[i] != nums[i - 1];
        }
        
        return nums[n - 1]; 
    }
};