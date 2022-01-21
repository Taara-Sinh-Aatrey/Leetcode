class Solution {
public:
    bool isPalindrome(string s) {
        
        for (char &ch : s) {
            if (isupper(ch))
                ch = tolower(ch);
        }
        
        int l = 0, r = int(s.size()) - 1;
        
        while (l < r) {
            while (l < r && !isalnum(s[l]))
                l++;
            
            while (r > l && !isalnum(s[r]))
                r--;
            
            if (l >= r) break;
            
            if (s[l] == s[r])
                l++, r--;
            else
                return false;
        }
        
        return true;
    }
};