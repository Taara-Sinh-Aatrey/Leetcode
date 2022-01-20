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
    ListNode* partition(ListNode* head, int x) {
        ListNode *lastSmaller = NULL;
        ListNode *prv = NULL;
        ListNode *cur = head;
        while (cur) {
            if (cur->val >= x) {
                prv = cur;
                cur = cur->next;
            }
            else {
                if (lastSmaller == prv) {
                    lastSmaller = cur;
                    prv = cur;
                    cur = cur->next;
                    continue;
                }
                ListNode* nxt = cur->next;
                if (lastSmaller == NULL) {
                    cur->next = head;
                    head = cur;
                }
                else {
                    cur->next = lastSmaller->next;
                    lastSmaller->next = cur;
                }
                lastSmaller = cur;
                prv->next = nxt;
                cur = nxt;
            }
        }
        return head;
    }
};