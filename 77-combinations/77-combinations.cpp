class Solution {
public:
    
    void rec (int num, int n, int k, vector<int> &curSol, vector<vector<int>> &ans) {
        if (curSol.size() == k) {
            ans.emplace_back(curSol);
            return;
        }
        if (num > n) {
            return;
        }
        curSol.emplace_back(num);
        rec(num + 1, n, k, curSol, ans);
        curSol.pop_back();
        rec(num + 1, n, k, curSol, ans);
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curSol;
        rec(1, n, k, curSol, ans);
        return ans;
    }
};