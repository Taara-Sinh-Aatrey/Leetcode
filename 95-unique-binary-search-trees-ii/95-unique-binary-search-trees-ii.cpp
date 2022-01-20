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
    
    vector<TreeNode*> generate(int n, int low, int high) {
        
        if (low > high)
            return {NULL};
        
        vector<TreeNode*> answer;
        
        for (int x = low; x <= high; x++) {
            vector<TreeNode*> leftRoots = generate(n, low, x - 1);
            vector<TreeNode*> rightRoots = generate(n, x + 1, high);
            for (TreeNode* leftRoot : leftRoots) {
                for (TreeNode* rightRoot : rightRoots) {
                    answer.emplace_back(new TreeNode(x, leftRoot, rightRoot));
                }
            }
        }
        
        return answer;
        
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return generate(n, 1, n);
    }
};