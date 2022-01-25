class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ab = 0;
        for (auto &num : nums)
            ab ^= num;
        
        int msb = 31 - __builtin_clz(ab);
        
        int a = 0;
        for (auto &num : nums)
            if (num >> msb & 1)
                a ^= num;
        
        return {a, a ^ ab};
    }
};