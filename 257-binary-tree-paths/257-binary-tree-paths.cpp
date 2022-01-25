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
    
    vector<string> ans;
    string cur;
    
    void TreePaths(TreeNode* root) {
        if (!root)
            return;
        
        string s = (!cur.empty() ? "->" : "") + to_string(root->val);
        cur += s;
        
        if (root->left == NULL and root->right == NULL)
            ans.emplace_back(cur);
        
        TreePaths(root->left);
        TreePaths(root->right);
        
        for (int x = 0; x < s.size(); x++)
            cur.pop_back();
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        TreePaths(root);
        return ans;
    }
};