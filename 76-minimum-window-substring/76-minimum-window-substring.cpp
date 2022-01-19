class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> cnt, cur;
        for (char &x : t) {
            cnt[x]++;
        }
            
        int n = s.size(), m = cnt.size();
        set<char> st;
        
        pair<int, int> ans{n + 1, 0};
        int j = 0;
        for (int i = 0; i < n; i++) {
            char &ch = s[i];
            cur[ch]++;
            if (cur[ch] == cnt[ch]) {
                st.insert(ch);
            }
            while (j < i && cur[s[j]] > cnt[s[j]]) {
                cur[s[j]]--;
                j++;
            }
            if (st.size() == m)
                ans = min(ans, pair(i - j + 1, j));
        }
        
        if (ans.first > n) {
            return "";
        }
        return s.substr(ans.second, ans.first);
    }
};