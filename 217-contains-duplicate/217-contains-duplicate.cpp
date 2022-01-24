class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> vis;
        
        for (auto &x : nums) {
            if (vis[x])
                return true;
            
            vis[x] = true;
        }
        
        return false;
    }
};