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
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) { 
        
        auto Push = [&] (stack<TreeNode*> &st, TreeNode* root) {
            while (root) {
                st.emplace(root);
                root = root->left;
            }
        };
        
        auto Pop = [&] (stack<TreeNode*> &st) {
            TreeNode *root = st.top();
            st.pop();
            Push(st, root->right);
            return root->val;
        };
        
        auto Top = [&] (stack<TreeNode*> &st) {
            return st.top()->val;
        };
        
        stack<TreeNode*> A, B;
        Push(A, root1);
        Push(B, root2);
        
        vector<int> ans;
        while (!A.empty() || !B.empty()) {
            if (B.empty() || (!A.empty() && Top(A) < Top(B))) {
                ans.emplace_back(Pop(A));
            }
            else {
                ans.emplace_back(Pop(B));
            }
        }
        
        return ans;
    }
};