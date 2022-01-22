class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int XOR = 0;
        for (auto &x : nums)
            XOR ^= x;
        return XOR;
    }
};