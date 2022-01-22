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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        ListNode *mid = head, *fast = head;
        while (fast->next && fast->next->next) {
            mid = mid->next;
            fast = fast->next->next;
        }
        
        ListNode *h1 = sortList(mid->next);
        
        mid->next = NULL;
        ListNode *h2 = sortList(head);
        
        ListNode *h = NULL, *prv = NULL;
        while (h1 || h2) {
            ListNode *mn = NULL;
            if (!h2 || (h1 && h1->val < h2->val)) {
                mn = h1;
                h1 = h1->next;
            }
            else {
                mn = h2;
                h2 = h2->next;
            }
            if (prv)
                prv->next = mn;
            else
                h = mn;
            prv = mn;
        }
        
        return h;
        
    }
};