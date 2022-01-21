/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    vector<int> curSol;
    vector<vector<int>> ans;
    
    void path_sum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return;
        
        targetSum -= root->val;
        curSol.emplace_back(root->val);
        
        if (root->left == NULL && root->right == NULL && targetSum == 0 && !curSol.empty())
            ans.emplace_back(curSol);
        
        path_sum(root->left, targetSum);
        path_sum(root->right, targetSum);
        
        curSol.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        path_sum(root, targetSum);
        return ans;
    }
};