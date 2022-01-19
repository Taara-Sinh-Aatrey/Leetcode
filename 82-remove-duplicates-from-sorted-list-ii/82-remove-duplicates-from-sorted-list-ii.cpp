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
        ListNode *cur = head;
        ListNode *prv = NULL;
        while (cur) {
            ListNode* cur2 = cur;
            int c = 0;
            while (cur2 && cur2->val == cur->val) {
                c++;
                cur2 = cur2->next;
            }
            if (c > 1) {
                if (prv == NULL) {
                    head = cur2;
                }
                else {
                    prv->next = cur2;
                }
            }
            else {
                prv = cur;
            }
            cur = cur2;
        }
        return head;
    }
};