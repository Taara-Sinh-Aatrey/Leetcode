/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    unordered_map<Node*, Node*> clone;
    
    Node* cloneGraph(Node* node) {
        if (node == NULL)
            return NULL;
        
        if (clone[node])
            return clone[node];
        
        Node* node_copy = new Node(node->val);
        clone[node] = node_copy;
            
        for (auto neighbor : node->neighbors) {
            node_copy->neighbors.emplace_back(cloneGraph(neighbor));
        }
        
        return clone[node] = node_copy;
    }
};