class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        const int MAX = 1 << 10;
        const int inf = 1e9;
        int n = nums.size();
        vector<int> dp(MAX, inf);
        dp[0] = 0;
        
        vector<int> max_freq(k), tot(k);
        int sum_changes = 0;
        // make every class equal to an element which exists at least once in that class
        for (int rem = 0; rem < k; rem++) {
            vector<int> ndp(MAX, inf), freq(MAX, 0);
            
            int total = 0;
            vector<int> v;
            for (int i = rem; i < n; i += k) {
                v.emplace_back(nums[i]);
                freq[nums[i]]++;
                total++;
            }
            
            for (auto &x : v) {
                for (int Xor = 0; Xor < MAX; Xor++) {
                    ndp[Xor ^ x] = min(ndp[Xor ^ x], dp[Xor] + (total - freq[x]));
                }
            }
            
            max_freq[rem] = *max_element(freq.begin(), freq.end()); 
            tot[rem] = total;
            sum_changes += total - max_freq[rem];
            
            swap(dp, ndp);
        }
        
        int ans = dp[0];
        
        // change all elements of a fixed class
        for (int fixed = 0; fixed < k; fixed++) {
            int cur = sum_changes - (tot[fixed] - max_freq[fixed]) + tot[fixed];
            ans = min(ans, cur);
        }
        
        return ans;
    }
};