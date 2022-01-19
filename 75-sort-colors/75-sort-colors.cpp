class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        vector<int> ptr(3, 0), cnt(3, 0);
        
        for (auto &x : nums) {
            cnt[x]++;
        }
        
        for (int i = 0; i < n; i++) {
            int req = 0;
            
            while (cnt[req] == 0)
                req++;
            cnt[req]--;
            
            int cur = nums[i];
            while (nums[ptr[req]] != req) {
                ptr[req]++;
            }
                        
            swap(nums[i], nums[ptr[req]]);
            
            ptr[req]++;
        }
        
    }
};