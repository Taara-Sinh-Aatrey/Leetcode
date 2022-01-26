class Solution {
public:
    int numSquares(int n) {
        const int inf = 1e9;
        vector<int> ans(n + 1, inf);
        
        for (int i = 0; i * i <= n; i++)
            ans[i * i] = 1;
        
        for (int i = 0; i < n; i++) {
            for (int j = 1; i + j * j <= n; j++) {
                ans[i + j * j] = min(ans[i + j * j], ans[i] + 1);
            }
        }
        
        return ans[n];
    }
};