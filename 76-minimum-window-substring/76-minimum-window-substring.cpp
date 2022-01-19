class Solution {
public:
    string minWindow(string s, string t) {
        // cnt is the count of every characters in `t`
        unordered_map<char, int> cnt;
        for (char &x : t) {
            cnt[x]++;
        }
            
        int n = s.size(), m = cnt.size();
        
        // `st` contains all the characters whose frequency in the current window is atleast 
        // the frequency of the same characters in the string `t`
        set<char> st;
        
        // `ans.first` is the length of the window and `ans.second` is the starting index of the window
        pair<int, int> ans{n + 1, 0};
        
        // `j` is the starting index of the current window
        int j = 0;
        
        // `cur` stores the frquency of every character in the current window
        unordered_map<char, int> cur;
        
        for (int i = 0; i < n; i++) {
            // including `i`th character in the current window
            char &ch = s[i];
            cur[ch]++;
            // if frequency of `ch` in the current window reached the frequency in the string `t`,
            // let's include it in the set `st`
            if (cur[ch] == cnt[ch]) {
                st.insert(ch);
            }
            
            // try removing unneccessary characters from the left end 
            while (j < i && cur[s[j]] > cnt[s[j]]) {
                cur[s[j]]--;
                j++;
            }
            
            // if the window has all the characters, consider it for the answer
            if (st.size() == m)
                ans = min(ans, pair(i - j + 1, j));
        }
        
        // this means we never found a working window having all the characters in the required amount
        if (ans.first > n) {
            return "";
        }
        
        // s.substr takes two parameters, 1st: the starting index and 2nd: the length of the substring
        return s.substr(ans.second, ans.first);
    }
};