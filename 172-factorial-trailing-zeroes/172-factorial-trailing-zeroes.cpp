class Solution {
public:
    int trailingZeroes(int n) {
        int a = 0, b = 0;
        for (int i = 2; i <= n; i++) {
            int x = i;
            while (x % 2 == 0)
                ++a, x /= 2;
            while (x % 5 == 0)
                ++b, x /= 5;
        }
        return min(a, b);
    }
};