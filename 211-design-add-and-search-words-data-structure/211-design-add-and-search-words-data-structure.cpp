class WordDictionary {
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
    
    WordDictionary() {
        root = new node();
    }
    
    void addWord(string word) {
        node* cur = root;
        
        for (int i = 0; i < word.size(); i++) {
            int ch = word[i] - 'a';
            
            if (!cur->child[ch])
                cur->child[ch] = new node();   
            
            cur = cur->child[ch];
        }
        cur->endOfWord = true;
    }
    
    bool search(string word, int idx, node* cur) {
        if (cur == NULL)
            return false;
        
        if (idx == word.size())
            return cur->endOfWord;
        
        char ch = word[idx];
        if (ch != '.')
            return search(word, idx + 1, cur->child[ch - 'a']);
        
        for (ch = 'a'; ch <= 'z'; ch++) {
            if (search(word, idx + 1, cur->child[ch - 'a']))
                return true;
        }
        
        return false;
    }
    
     bool search(string word) {
         return search(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */