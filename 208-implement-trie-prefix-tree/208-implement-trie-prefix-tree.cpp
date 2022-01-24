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
    
    Trie() {
        root = new node();
    }
    
    void insert(string word) {
        node* cur = root;
        
        for (int i = 0; i < word.size(); i++) {
            int ch = word[i] - 'a';
            
            if (!cur->child[ch])
                cur->child[ch] = new node();   
            
            cur = cur->child[ch];
        }
        cur->endOfWord = true;
    }
    
    bool search(string word) {
        node* cur = root;
            
        for (int i = 0; i < word.size(); i++) {
            cur = cur->child[word[i] - 'a'];
            
            if (!cur) return false;
        }
        return cur->endOfWord;
    }
    
    bool startsWith(string prefix) {
        node* cur = root;
            
        for (int i = 0; i < prefix.size(); i++) {
            cur = cur->child[prefix[i] - 'a'];
            
            if (!cur) return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */