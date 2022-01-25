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
    
    int kth_Smallest(TreeNode* root, int &k) {
        if (!root)
            return -1;

        int num = kth_Smallest(root->left, k);
        if (num != -1)
            return num;
        
        if (k == 1)
            return root->val;
        
        k--;
        return kth_Smallest(root->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        return kth_Smallest(root, k);
    }
};