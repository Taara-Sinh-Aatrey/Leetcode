class Solution {
public:
    int generate(int n, vector<int> &dp) {
        if (n == 0)
            return 1;
        
        int &answer = dp[n];
        
        if (answer != -1)
            return answer;
        
        answer = 0;
        
        for (int x = 0; x < n; x++)
            answer += generate(x, dp) * generate(n - 1 - x, dp);

        return answer;
    }
    
    int numTrees(int n) {
        vector<int> dp(n + 1, -1);
        
        return generate(n, dp);
    }
};