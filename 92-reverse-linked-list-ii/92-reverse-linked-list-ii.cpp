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
    
    void reverse (ListNode* start, ListNode* end) {
        ListNode *cur = start;
        ListNode *prv = NULL;
        while (true) {
            ListNode *nxt = cur->next;
            cur->next = prv;
            if (cur == end)
                break;
            prv = cur;
            cur = nxt;
        };
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        --left, --right;
        right -= left;
        
        ListNode *beforeStart = NULL;
        ListNode* start = head;
        while (left > 0) {
            beforeStart = start;
            start = start->next;
            left--;
        }
        
        ListNode* end = start;
        while (right > 0) {
            end = end->next;
            right--;
        }
        ListNode* afterEnd = end->next;
        
        reverse(start, end);
        
        if (beforeStart == NULL) {
            head = end;
        }
        else {
            beforeStart->next = end;
        }
        
        start->next = afterEnd;
        
        return head;
        
    }
};