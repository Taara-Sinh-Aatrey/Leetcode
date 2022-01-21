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
    
    unordered_map<TreeNode*, int> h;
    
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        return h[root] = 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    
    bool balanced(TreeNode* root) {
        if (root == NULL)
            return true;
        
        return abs(h[root->left] - h[root->right]) <= 1 && balanced(root->left) && balanced(root->right);
        
    }
    
    bool isBalanced(TreeNode* root) {
        
        maxDepth(root);
        
        return balanced(root);
        
    }
};