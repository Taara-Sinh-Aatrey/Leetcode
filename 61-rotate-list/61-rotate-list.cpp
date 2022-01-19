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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return head;
        int n = 0;
        ListNode *cur = head;
        ListNode *tail = head;
        while (cur) {
            tail = cur;
            n++;
            cur = cur->next;
        }
        k %= n;
        if (k == 0)
            return head;
        k = n - k;
        int cnt = 0;
        cur = head;
        ListNode *prev = NULL;
        while (cnt < k) {
            prev = cur;
            cur = cur->next;
            cnt++;
        }
        tail->next = head;
        prev->next = NULL;
        return cur;
    }
};