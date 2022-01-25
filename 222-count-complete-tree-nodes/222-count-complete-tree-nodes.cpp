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
    
    int leftHeight (TreeNode* root) {
        int depth = 0;
        while (root) {
            depth++;
            root = root->left;
        }
        return depth;
    }
    
    int rightHeight (TreeNode* root) {
        int depth = 0;
        while (root) {
            depth++;
            root = root->right;
        }
        return depth;
    }
    
    int countNodes(TreeNode* root) {
        int lH = leftHeight(root);
        int rH = rightHeight(root);
        if (lH == rH)
            return (1 << lH) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};