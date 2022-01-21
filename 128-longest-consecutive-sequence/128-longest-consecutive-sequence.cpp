class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> idx;
        
        for (auto &x : nums)
            idx[x] = true;
        
        int ans = 0;
        
        for (auto &x : nums) {
            if (!idx[x])
                continue;
            
            int cnt = 1;
            idx[x] = false;
            
            int y = x + 1;
            while (idx[y]) {
                idx[y] = false;
                cnt++;
                y++;
            }
            
            y = x - 1;
            while (idx[y]) {
                idx[y] = false;
                cnt++;
                y--;
            }
            
            ans = max(ans, cnt);
        }
        
        return ans;
    }
};