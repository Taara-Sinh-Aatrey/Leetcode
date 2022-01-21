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
    int sumNumbers(TreeNode* root, int cur = 0) {
        if (root == NULL)
            return 0;
        
        cur = cur * 10 + root->val;
        
        if (root->left == NULL && root->right == NULL)
            return cur;
        
        return sumNumbers(root->left, cur) + sumNumbers(root->right, cur);
            
    }
};