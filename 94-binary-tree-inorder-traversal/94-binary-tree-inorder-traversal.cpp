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
    
    void inorder(TreeNode* root, vector<int> &tour) {
        if (!root) return;
        inorder(root->left, tour);
        tour.emplace_back(root->val);
        inorder(root->right, tour);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> tour;
        inorder(root, tour);
        return tour;
    }
};