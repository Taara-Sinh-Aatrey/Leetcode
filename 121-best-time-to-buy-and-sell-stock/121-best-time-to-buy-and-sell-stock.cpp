class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        int mn = 1e9, ans = 0;
        
        for (auto &x : prices) {
            
            ans = max(ans, x - mn);
            
            mn = min(mn, x);
        }
        
        return ans;
    }
};