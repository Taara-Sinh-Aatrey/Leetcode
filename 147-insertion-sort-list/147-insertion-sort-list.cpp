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
    ListNode* insertionSortList(ListNode* head) {
        if (!head)
            return NULL;
        
        ListNode *cur = head->next, *prv = head;
        while (cur) {
            if (cur->val >= prv->val) {
                prv = cur;
                cur = cur->next;
                continue;
            }
            
            auto nxt = cur->next;
            
            if (cur->val <= head->val) {
                cur->next = head;
                head = cur;
            }
            else {
                auto cur2 = head;
                ListNode* prv2 = NULL;
                
                while (cur2 && cur2->val < cur->val) {
                    prv2 = cur2;
                    cur2 = cur2->next;
                }
                
                prv2->next = cur;
                cur->next = cur2;
            }
            
            prv->next = nxt;
            cur = nxt;
            
        }
        
        return head;
    }
};