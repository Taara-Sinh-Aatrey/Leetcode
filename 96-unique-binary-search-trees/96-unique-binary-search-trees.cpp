class Solution {
public:
    int generate(int n, int low, int high, vector<vector<int>> &dp) {
        if (low > high)
            return 1;
        
        int &answer = dp[low][high];
        
        if (answer != -1)
            return answer;
        
        answer = 0;
        
        for (int x = low; x <= high; x++)
            answer += generate(n, low, x - 1, dp) * generate(n, x + 1, high, dp);

        return answer;
    }
    
    int numTrees(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        
        return generate(n, 1, n, dp);
    }
};