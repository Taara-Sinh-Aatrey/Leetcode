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
    ListNode *detectCycle(ListNode *head) {
        const int visitedVal = INT_MAX;
        
        while (head) {
            if (head->val == visitedVal)
                return head;
            
            head->val = visitedVal;
            head = head->next;
        }
        
        return NULL;
    }
};