class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        int ans = INT_MIN;
        pair<int, int> cur{1, 1};
        
        for (auto &x : nums) {
            cur = minmax({x, cur.first * x, cur.second * x});
            ans = max(ans, cur.second);
        }
        
        return ans;
    }
};