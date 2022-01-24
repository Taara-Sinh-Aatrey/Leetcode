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

class Solution {
public:
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
      
        Trie trie;
        for (auto &word : words)
            trie.insert(word);
        
        vector<string> ans;
        
        int n = board.size(), m = board[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
        
                const int dr[] = {-1, 0, 1, 0};
                const int dc[] = {0, -1, 0, 1};
                
                string s;
                
                function<void(int, int, Trie::node*)> dfs = [&] (int r, int c, Trie::node* cur) -> void {                    
                    // assert(cur);
                    
                    char t = board[r][c];
                    // cur = cur->child[t - 'a'];
                    
                    // if (!cur)
                        // return;
                    
                    s += t;
                    board[r][c] = '?';
                    
                    if (cur->endOfWord) {
                        cur->endOfWord = false;
                        ans.emplace_back(s);
                    }
                    
                    for (int dir = 0; dir < 4; dir++) {
                        int nr = r + dr[dir];
                        int nc = c + dc[dir];
                        if (0 <= nr && nr < n && 0 <= nc && nc < m && board[nr][nc] != '?' && cur->child[board[nr][nc] - 'a']) {
                            dfs(nr, nc, cur->child[board[nr][nc] - 'a']);
                        }
                    }
                    
                    board[r][c] = t;
                    s.pop_back();
                };
                
                if (trie.root->child[board[i][j] - 'a'])
                    dfs(i, j, trie.root->child[board[i][j] - 'a']);
            }
        }
        
        return ans;
    }
};