class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int half = -1e9, one = 0, oneAndHalf = -1e9, two = 0;
        
        for (auto &x : prices) {
            two = max(two, oneAndHalf + x);
            
            oneAndHalf = max(oneAndHalf, one - x);
            
            one = max(one, half + x);
            
            half = max(half, 0 - x);
        }
        
        return max(one, two);
    }
};