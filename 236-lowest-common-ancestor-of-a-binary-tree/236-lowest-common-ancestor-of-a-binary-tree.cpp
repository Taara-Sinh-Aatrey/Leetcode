/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode *lca = NULL;
    
    pair<bool, bool> LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return {false, false};
        
        auto left = LCA(root->left, p, q);
        auto right = LCA(root->right, p, q);
        
        pair<bool, bool> ret = {left.first || right.first || p == root, left.second || right.second || q == root};
        
        if (ret.first && ret.second && lca == NULL)
            lca = root;
        
        return ret;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        LCA(root, p, q);
        
        return lca;
        
    }
};