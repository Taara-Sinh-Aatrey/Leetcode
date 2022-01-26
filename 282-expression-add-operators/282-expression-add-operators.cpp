class Solution {
public:
    
    vector<string> ans;
    
    void rec (string &num, int idx, int target, string cur, int64_t val, int64_t prev) {
        if (idx == num.size()) {
            if (val == target)
                ans.emplace_back(cur);
            return;
        }
        
        int64_t v = 0;
        string s = "";
        for (int i = idx; i < num.size(); i++) {
            s += num[i];
            v = v * 10 + (num[i] - '0');
            
            if (num[idx] == '0' && i > idx)
                break;
            
            if (idx == 0) {
                rec(num, i + 1, target, s, v, v);
                continue;
            }
            
            rec(num, i + 1, target, cur + "+" + s, val + v, v);
            rec(num, i + 1, target, cur + "-" + s, val - v, -v);
            rec(num, i + 1, target, cur + "*" + s, val - prev + prev * v, prev * v);
        }
    }
    
    vector<string> addOperators(string num, int target) {
        int n = num.size();
        rec(num, 0, target, "", 0, 0);
        return ans;
    }
};