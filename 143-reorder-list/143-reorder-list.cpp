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
class Solution {
public:
    void reorderList(ListNode* head) {
        
        if (!head)
            return;
        
        vector<ListNode*> ptrs;
        
        while (head) {
            ptrs.emplace_back(head);
            head = head->next;
        }
        
        int n = ptrs.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            if (low == high) {
                ptrs[low]->next = NULL;
            }
            else {
                ptrs[low]->next = ptrs[high];
                if (low + 1 != high) {
                    ptrs[high]->next = ptrs[low + 1];
                }
                else {
                    ptrs[high]->next = NULL;
                }
            }
            low++, high--;
        }
    }
};