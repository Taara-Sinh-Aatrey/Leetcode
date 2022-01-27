class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        for (auto &x : nums) {
            if (lis.empty() || x > lis.back())
                lis.emplace_back(x);
            else
                *lower_bound(lis.begin(), lis.end(), x) = x;
        }
        return lis.size();
    }
};