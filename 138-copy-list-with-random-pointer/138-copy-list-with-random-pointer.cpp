/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    
    unordered_map<Node*, Node*> copy;
    
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;
        
        if (copy[head])
            return copy[head];
        
        Node *head_copy = new Node(head->val);
        
        copy[head] = head_copy;
        
        head_copy->next = copyRandomList(head->next);
        
        head_copy->random = copyRandomList(head->random);
        
        return head_copy;
    }
};