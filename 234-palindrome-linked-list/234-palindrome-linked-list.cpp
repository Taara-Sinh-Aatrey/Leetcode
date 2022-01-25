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
    
    ListNode* reverse(ListNode *head) {
        ListNode *prv = NULL, *cur = head;
        
        while (cur) {
            ListNode *nxt = cur->next;
            cur->next = prv;
            
            prv = cur;
            cur = nxt;
        }
        
        return prv;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode *mid = head, *fast = head;
        while (fast->next and fast->next->next) {
            mid = mid->next;
            fast = fast->next->next;
        }
        
        ListNode *head2 = mid->next;
        head2 = reverse(head2);
        
        while (head && head2) {
            if (head->val != head2->val)
                return false;
            head = head->next;
            head2 = head2->next;
        }
        
        return true;
    }
};