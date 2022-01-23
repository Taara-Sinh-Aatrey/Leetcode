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
    
    vector<int> ans;
    
    void dfs (TreeNode *root, int id = 1) {
        if (!root) return;
        
        if (id > ans.size())
            ans.emplace_back(root->val);
        
        dfs(root->right, id + 1);
        dfs(root->left, id + 1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        dfs(root);
        
        return ans;
    }
};