class Solution {
public:
    int maximumGap(vector<int>& nums) {
        
        int n = nums.size();
        if(n <= 1) 
            return 0;
        
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        
        int avg_gap = (mx - mn + n - 2) / (n - 1);
        if (avg_gap == 0) 
            return 0;
        
        vector<int> bucket_max(n, INT_MIN), bucket_min(n, INT_MAX);
        for (int i = 0; i < n; i++) {
            int index = (nums[i] - mn) / avg_gap;
            
            bucket_min[index] = min(bucket_min[index], nums[i]);
            bucket_max[index] = max(bucket_max[index], nums[i]);
        }
        
        int prv = mn, ans = 0;
        for (int i = 0; i < n; i++) {
            if (bucket_max[i] == INT_MIN)
                continue;
            
            ans = max(ans, bucket_min[i] - prv);
            prv = bucket_max[i];
        }
        ans = max(ans, mx - prv);
        
        return ans;
    }
};