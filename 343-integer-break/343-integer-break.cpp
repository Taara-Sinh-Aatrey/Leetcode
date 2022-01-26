class Solution {
public:
    int integerBreak(int n) {
    
        // int ans = 0;
        // int k = -1;
        
        int m = max(2, (n + 1) / 3);
            
            int each = n / m;
            int rem = n % m;
            
            int prod = 1;
            for (int i = 0; i < m; i++)
                prod *= each + (i < rem ? 1 : 0);
            
            // if (prod > ans)
            //     k = m;
            // ans = max(ans, prod);
        
        // cout << k << endl;
        
        return prod;
    }
};