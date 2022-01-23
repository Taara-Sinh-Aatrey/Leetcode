#define msb(x) (int) (31 - __builtin_clz(x))

class Solution {
public:
    
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        while (left and right && msb(left) == msb(right)) {
            ans |= 1 << msb(left);
            left ^= 1 << msb(left);
            right ^= 1 << msb(right);
        }
        return ans;
    }
};