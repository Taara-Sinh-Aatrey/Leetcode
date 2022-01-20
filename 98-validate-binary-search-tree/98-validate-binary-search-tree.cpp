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
    bool isValidBST(TreeNode* root, int64_t low = -1e18, int64_t high = 1e18) {
        if (!root) 
            return true;
        
        if (root->val < low || root->val > high)
            return false;
        
        return isValidBST(root->left, low, int64_t(root->val) - 1) && isValidBST(root->right, int64_t(root->val) + 1, high);
        
    }
};