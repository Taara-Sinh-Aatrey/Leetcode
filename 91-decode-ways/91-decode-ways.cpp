class Solution {
public:
    
    int numDecodings(string s) {
        // ASSUMING 1 BASED INDEXING IN DP
        int n = s.size();
        
        // dp[i] represents the number of ways to decode the string s[1].s[2]......s[i-1]..s[i]
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        
        for (int i = 1; i <= n; i++) {
            
            // checking if the current character is not '0' since '0' is not avaiable for mapping
            if (s[i - 1] != '0')
            // so i decoded ith character, now let's decode s[1]..s[2]........s[i-2]...s[i-1]
                dp[i] += dp[i - 1];
            
            if (i > 1 && s[i - 2] != '0') {
                
                int code = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
                
                if (code <= 26)
                // so i decoded (s[i - 1]...s[i]) substring, now let's decode s[1]..s[2]........s[i-3]...s[i-2]
                    dp[i] += dp[i - 2];
                
            }
            
        }
        
        return dp.back();
    }
};