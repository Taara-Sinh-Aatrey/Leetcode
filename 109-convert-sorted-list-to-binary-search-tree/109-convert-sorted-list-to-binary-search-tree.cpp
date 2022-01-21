/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    TreeNode* sortedArrayToBST(vector<int>& nums, int l = 0, int r = INT_MIN) {
        
        if (r == INT_MIN)
            r = int(nums.size()) - 1;
        
        if (l > r)
            return NULL;
        
        int mid = (l + r) / 2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = sortedArrayToBST(nums, l, mid - 1);
        
        root->right = sortedArrayToBST(nums, mid + 1, r);
        
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while (head) {
            nums.emplace_back(head->val);
            head = head->next;
        }
        return sortedArrayToBST(nums);
    }
};