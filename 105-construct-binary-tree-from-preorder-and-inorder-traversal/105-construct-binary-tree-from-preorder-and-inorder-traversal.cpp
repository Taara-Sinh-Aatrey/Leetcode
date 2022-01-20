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
        
        int j = start2;
        while (inorder[j] != preorder[start])
            j++;
        
        TreeNode *root = new TreeNode(preorder[start]);
        root->left = buildTree(preorder, inorder, start + 1, start + j - start2, start2, j - 1);
        root->right = buildTree(preorder, inorder, start + j - start2 + 1, end, j + 1, end2);
        
        return root;
    }
};