/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto cur = headA;
        while (cur) {
            cur->val *= -1;
            cur = cur->next;
        }
        ListNode *ans = NULL;
        while (headB) {
            if (headB->val < 0) {
                ans = headB;
                break;
            }
            headB = headB->next;
        }
        cur = headA;
        while (cur) {
            cur->val *= -1;
            cur = cur->next;
        }
        return ans;
    }
};