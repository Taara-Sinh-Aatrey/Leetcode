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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL)
            return vector<vector<int>>();
        
        vector<vector<int>> levels{{root->val}};
        queue<TreeNode*> q{{root}};
        
        while (!q.empty()) {
            
            queue<TreeNode*> nq;
            levels.emplace_back();
            vector<int> &level = levels.back();
            
            while (!q.empty()) {
                TreeNode *root = q.front();
                q.pop();
                
                if (root->left) {
                    level.emplace_back(root->left->val);
                    nq.emplace(root->left);
                }
                
                if (root->right) {
                    level.emplace_back(root->right->val);
                    nq.emplace(root->right);
                }
            }
            
            if (level.empty()) {
                levels.pop_back();
            }
            
            swap(q, nq);
            
        }
        
        return levels;
    }
};