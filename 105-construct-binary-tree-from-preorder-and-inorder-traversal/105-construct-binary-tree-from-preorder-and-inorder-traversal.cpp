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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int start = 0, int end = -1, int start2 = 0, int end2 = -1) {
        if (end == -1)
            end = int(preorder.size()) - 1;
        
        if (end2 == -1)
            end2 = int(inorder.size()) - 1;

        if (start > end)
            return NULL;
        
        int len = 0;
        while (inorder[start2 + len] != preorder[start])
            len++;
        
        TreeNode *root = new TreeNode(preorder[start]);
        
        root->left = buildTree(preorder, inorder, start + 1, start + len, start2, start2 + len - 1);
        
        root->right = buildTree(preorder, inorder, start + len + 1, end, start2 + len + 1, end2);
        
        return root;
    }
};