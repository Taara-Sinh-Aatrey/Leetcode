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
class BSTIterator {
public:
    
    vector<pair<TreeNode*, int>> st;
    
    BSTIterator(TreeNode* root) {
        if (root)
            st.emplace_back(root, 0);
    }
    
    int next() {
        assert(hasNext() && st.back().second == 1);
        st.back().second++;
        return st.back().first->val;
    }
    
    bool hasNext() {
        while (!st.empty()) {
            auto [root, state] = st.back();
            
            if (state == 3) {
                st.pop_back();
                continue;
            }
            
            if (state == 1)
                return true;
            
            st.back().second++;
            
            if (state == 0 && root->left)
                st.emplace_back(root->left, 0);
            else if (state == 2 && root->right)
                st.emplace_back(root->right, 0);
        }
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */