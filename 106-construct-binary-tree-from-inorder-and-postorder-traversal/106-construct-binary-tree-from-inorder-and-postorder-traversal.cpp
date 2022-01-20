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

// left root right

// left right root

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int start = 0, int end = INT_MIN, int start2 = 0, int end2 = INT_MIN) {
        
        if (end == INT_MIN)
            end = int(inorder.size()) - 1;
        
        if (end2 == INT_MIN)
            end2 = int(postorder.size()) - 1;

        if (start > end)
            return NULL;
        
        int len = 0;
        while (inorder[start + len] != postorder[end2])
            len++;
        
        TreeNode *root = new TreeNode(inorder[start + len]);
        
        root->left = buildTree(inorder, postorder, start, start + len - 1, start2, start2 + len - 1);
        
        root->right = buildTree(inorder, postorder, start + len + 1, end, start2 + len, end2 - 1);
        
        return root;
    }
};