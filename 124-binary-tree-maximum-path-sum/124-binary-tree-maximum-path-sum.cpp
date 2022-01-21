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
    
    int ans = -1000;
    
    int maxSum(TreeNode* root) {
        if (!root)
            return -1000;
        
        int left = maxSum(root->left);
        int right = maxSum(root->right);
        
        ans = max(ans, left + root->val + right);
                  
        int vertical = max({left + root->val, right + root->val, root->val});
                  
        ans = max(ans, vertical);
        
        return vertical;
        
    }
    
    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return ans;
        
    }
};