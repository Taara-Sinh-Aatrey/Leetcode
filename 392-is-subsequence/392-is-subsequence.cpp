class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, n = s.size();
        
        for (auto &ch : t) {
            if (i < n && s[i] == ch)
                i++;
        }
        
        return i == n;
    }
};