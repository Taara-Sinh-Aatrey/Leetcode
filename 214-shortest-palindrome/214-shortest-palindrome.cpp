class Solution {
public:
    
    string shortestPalindrome(string s) {
        int n = s.size();
        
        string rev = s;
        reverse(rev.begin(), rev.end());
        s = s + "#" + rev;
        
        int len = 0;
        vector<int> lps(s.size(), 0);
        for (int i = 1; i < s.size(); i++) {
            while (len > 0 && s[i] != s[len])
                len = lps[len - 1];
            
            if (s[i] == s[len])
                len++;
            
            lps[i] = len;
        }
        
        return rev.substr(0, n - lps.back()) + s.substr(0, n);
    }
};