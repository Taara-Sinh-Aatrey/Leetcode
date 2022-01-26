class Solution {
public:
    int integerBreak(int n) {
        
        int m = max(2, (n + 1) / 3);

        int prod = 1;
        for (int i = 0; i < m; i++)
            prod *= n / m + (i < (n % m) ? 1 : 0);
        
        return prod;
    }
};