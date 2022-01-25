class Solution {
public:
    vector<int> diffWaysToCompute(string s) {
        int n = s.size();
        vector<int> dp[n][n];
        
        for (int i = n - 1; i >= 0; i--) {
            
            if (!isdigit(s[i]) or (i > 0 && isdigit(s[i - 1])))
                continue;
            
            int cur = 0, j = i;
            while (j < n && isdigit(s[j]))
                cur = cur * 10 + (s[j++] - '0');
            
            dp[i][j - 1] = {cur};
            
            for (; j < n; j++) {
                
                if (!isdigit(s[j]) or (j + 1 < n && isdigit(s[j + 1])))
                    continue;
                
                for (int k = i; k <= j; k++) {
                    if (isdigit(s[k]))
                        continue;
                    
                    for (auto &x : dp[i][k - 1]) {
                        for (auto &y : dp[k + 1][j]) {
                            dp[i][j].emplace_back(s[k] == '+' ? x + y : (s[k] == '-' ? x - y : x * y));
                        }
                    }
                }
            }
        }
        
        return dp[0][n - 1];
    }
};