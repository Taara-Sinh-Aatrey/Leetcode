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
    void inorderTraverse(TreeNode* root, vector<TreeNode*> &in){
        
        if(!root)
            return;
        
        inorderTraverse(root->left, in);
        
        in.emplace_back(root);
        
        inorderTraverse(root->right, in);
    }
    
    void recoverTree(TreeNode* root) {
        
        vector<TreeNode*>in;
        
        inorderTraverse(root, in);
        
        TreeNode* prev = in[0], *first = NULL, *sec = NULL;
        
        for (int i = 1; i < in.size(); i++) {
            if (prev->val > in[i]->val) {
                if (first == NULL)
                    first = prev;
                sec = in[i];
            }
            prev = in[i];
        }
        
        swap(first->val, sec->val);
        
    }
};