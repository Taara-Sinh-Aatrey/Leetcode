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
    
    TreeNode* flattenTree(TreeNode* root) {
        
        if (root == NULL)
            return root;
        
        TreeNode *tail = root;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        
        if (left) {
            TreeNode *tail2 = flattenTree(left);
            tail->left = NULL;
            tail->right = left;
            tail = tail2;
        }
        
        if (right) {
            TreeNode *tail2 = flattenTree(right);
            tail->left = NULL;
            tail->right = right;
            tail = tail2;
        }
        
        return tail;
    }
    
    void flatten(TreeNode* root) {
        flattenTree(root);
    }
};