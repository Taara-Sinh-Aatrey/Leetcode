class Solution {
public:
    
    vector<vector<string>> ans;
    vector<string> cur;
    
    void rec(string s, int i) {
        if (i == s.size()) {
            ans.emplace_back(cur);
            return;
        }
        
        for (int j = i; j < s.size(); j++) {
            
            bool ok = true;
            for (int x = i, y = j; x < y; x++, y--) {
                if (s[x] != s[y]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;
            
            cur.emplace_back(s.substr(i, j - i + 1));
            
            rec(s, j + 1);
            
            cur.pop_back();
            
        }
    }
    
    vector<vector<string>> partition(string s) {
        
        rec(s, 0);
        
        return ans;
    }
};