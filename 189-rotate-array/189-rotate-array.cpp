class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        if (k != 0) {
            nums.insert(nums.end(), nums.begin(), nums.begin() + n - k);
            nums.erase(nums.begin(), nums.begin() + n - k);
        }
    }
};