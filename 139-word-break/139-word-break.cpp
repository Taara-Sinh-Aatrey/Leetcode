class Solution {
public:
    
    class Trie {
    public:
        
        struct node {
            vector<node*> child;
            bool endOfWord;
            
            node () {
                endOfWord = false;
                child = vector<node*>(26, NULL);
            }
        };
        
        node *root;
        
        Trie () {
            root = new node();
        }
        
        node* add (string &s, int idx = 0, node *cur = NULL) {
            if (cur == NULL) cur = root;
            
            for (int i = idx; i < s.size(); i++) {
                int ch = s[i] - 'a';
                
                if (!cur->child[ch])
                    cur->child[ch] = new node();   
                
                cur = cur->child[ch];
            }
            cur->endOfWord = true;
            return cur;
        }
        
        node* search (string &s, int idx = 0, node *cur = NULL) {
            if (cur == NULL) cur = root;
                
            for (int i = idx; i < s.size(); i++) {
                cur = cur->child[s[i] - 'a'];
                
                if (!cur) break;
            }
            return cur;
        }
        
    };
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        
        Trie trie;
        for (string &s : wordDict)
            trie.add(s);
        
        vector<bool> dp(n + 1);
        dp[n] = true;
        for (int i = n - 1; i >= 0; i--) {
            string cur = "";
            auto ptr = trie.root;
            for (int j = i; j < n; j++) {
                cur += s[j];
                ptr = trie.search(cur, j - i, ptr);
                if (!ptr) break;
                if (ptr->endOfWord && dp[j + 1]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};