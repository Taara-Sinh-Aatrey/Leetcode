class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans{{}};
        for (auto &x : nums) {
            int sz = ans.size();
            for (int i = 0; i < sz; i++) {
                auto vec = ans[i];
                vec.emplace_back(x);
                ans.emplace_back(vec);
            }
        }
        return ans;
    }
};