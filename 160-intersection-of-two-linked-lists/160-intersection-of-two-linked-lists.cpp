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

    int count (ListNode *head) {
        int cnt = 0;
        while (head) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    
    ListNode* move (ListNode *head, int amt) {
        while (amt > 0 && head) {
            amt--;
            head = head->next;
        }
        return head;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int cntA = count(headA), cntB = count(headB);
        
        if (cntA > cntB)
            headA = move(headA, cntA - cntB);
        else if (cntB > cntA)    
            headB = move(headB, cntB - cntA);
        
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        
        return headA;
    }
};