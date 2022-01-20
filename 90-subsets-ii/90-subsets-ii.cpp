class Solution {
public:
    
    void generateSubsets (vector<int> &nums, int idx, vector<int> &curSol, vector<vector<int>> &res) {
        
        res.emplace_back(curSol);
        
        if (idx >= nums.size()) {
            return;
        }
        
        for (int i = idx; i < nums.size(); i++) {
            if (i == idx || nums[i] != nums[i - 1]) {
                curSol.emplace_back(nums[i]);
                generateSubsets(nums, i + 1, curSol, res);
                curSol.pop_back();
            }
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curSol;
        vector<vector<int>> res;
        generateSubsets(nums, 0, curSol, res);
        return res;
    }
};