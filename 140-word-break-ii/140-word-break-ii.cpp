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
    
    vector<string> ans;
    string cur = "";
    Trie trie;
    
    void rec (string &s, int idx = 0) {
        
        if (idx == s.size()) {
            ans.emplace_back(cur);
            return;
        }
        
        string str = "";
        auto ptr = trie.root;
        for (int i = idx; i < s.size(); i++) {
            
            str += s[i];
            ptr = trie.search(str, i - idx, ptr);
            
            if (!ptr) break;
            
            if (ptr->endOfWord) {
                cur += str;
                if (i + 1 < s.size())
                    cur += ' ';
                
                rec (s, i + 1);
                
                if (i + 1 < s.size())
                    cur.pop_back();
                for (int j = 0; j < str.size(); j++)
                    cur.pop_back();
            }
        }
        
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        for (auto &s : wordDict)
            trie.add(s);
        
        rec(s);
        
        return ans;
    }
};