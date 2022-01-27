/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        string ans = "";
        q.emplace(root);
        
        while (!q.empty()) {
            root = q.front();
            q.pop();
            
            if (root) {
                ans += to_string(root->val);
                q.emplace(root->left);
                q.emplace(root->right);
            }
            else
                ans += "null";
            
            ans += ',';
        }
        
        ans.pop_back();
        cout << ans << endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<TreeNode*> nodes;
        int idx = -1;
        TreeNode *head = NULL;
        
        int i = 0;
        while (i < data.size()) {
            int j = i;
            string cur = "";
            while (j < data.size() && data[j] != ',')
                cur += data[j++];
            if (cur != "null") {
                TreeNode *node = new TreeNode(stoi(cur));
                if (idx != -1) {
                    nodes[idx]->left = node;
                }
                else {
                    head = node;
                }
                nodes.emplace_back(node);
            }
            i = j + 1;
            
            if (idx == -1) {
                idx++;
                continue;
            }
            
            j = i;
            cur = "";
            while (j < data.size() && data[j] != ',')
                cur += data[j++];
            if (cur != "null") {
                TreeNode *node = new TreeNode(stoi(cur));
                nodes[idx]->right = node;
                nodes.emplace_back(node);
            }
            i = j + 1;
            idx++;
        }
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));