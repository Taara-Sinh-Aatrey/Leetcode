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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return head;
        ListNode *prv = head;
        ListNode *cur = head->next;
        while (cur) {
            if (cur->val == prv->val) {
                prv->next = cur->next;
            }
            else {
                prv = cur;
            }
            cur = cur->next;
        }
        return head;
    }
};