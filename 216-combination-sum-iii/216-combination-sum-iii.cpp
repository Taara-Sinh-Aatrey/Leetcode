class Solution {
public:
    
    vector<vector<int>> ans;
    vector<int> cur;
    
    void rec(int low, int remTake, int remSum) {
        if (remTake < 0 || remSum < 0)
            return;
        
        if (remSum == 0 && remTake == 0) {
            ans.emplace_back(cur);
            return;
        }
        
        if (low > 9)
            return;
        
        rec(low + 1, remTake, remSum);
        
        cur.emplace_back(low);
        rec(low + 1, remTake - 1, remSum - low);
        cur.pop_back();
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        rec(1, k, n);
        
        return ans;
    }
};