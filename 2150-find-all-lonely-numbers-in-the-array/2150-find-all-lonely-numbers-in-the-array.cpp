class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        map<int, int> mp;
        for (auto &x : nums)
            mp[x]++;
        vector<int> ans;
        for (auto &[x, y] : mp) {
            if (mp[x - 1] || mp[x + 1] || mp[x] > 1)
                continue;
            ans.emplace_back(x);
        }
        return ans;
    }
};