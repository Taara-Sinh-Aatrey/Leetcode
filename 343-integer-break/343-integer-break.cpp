class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3)
            return n-1;
        
        int prod = 1;
        while (n > 4) {
            n -= 3;
            prod *= 3;
        }
        
        return prod * n;
    }
};