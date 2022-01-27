class Solution {
public:
    
    set<string> ans;
    string cur;
    
    void recurse (string &s, int idx, int remLeft, int remRight, int score) {       
        if (idx == s.size()) {
            if (remLeft == 0 && remRight == 0)
                ans.emplace(cur);
            return;
        }
        
        if (s[idx] != '(' && s[idx] != ')') {
            cur += s[idx];
            recurse(s, idx + 1, remLeft, remRight, score);
            cur.pop_back();
            return;
        }
        
        if (s[idx] == '(' && remLeft > 0) {
            cur += '(';
            recurse(s, idx + 1, remLeft - 1, remRight, score + 1);
            cur.pop_back();
        }
        else if (s[idx] == ')' && remRight > 0 && score > 0) {
            cur += ')';
            recurse(s, idx + 1, remLeft, remRight - 1, score - 1);
            cur.pop_back();
        }
        
        recurse(s, idx + 1, remLeft, remRight, score);
    }
    
    vector<string> removeInvalidParentheses(string s) {
        int pairs = 0, score = 0;
        
        for (char &ch : s) {
            if (ch == '(') {
                score++;
            }
            else if (ch == ')' && score > 0) {
                pairs++;
                score--;
            }
        }
        
        recurse(s, 0, pairs, pairs, 0);
        
        return vector<string>(ans.begin(), ans.end());
    }
};