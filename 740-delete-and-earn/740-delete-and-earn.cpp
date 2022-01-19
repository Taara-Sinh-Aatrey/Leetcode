class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        const int N = 1e4 + 1;
        
        vector<int> freq(N);
        for (auto &x : nums) {
            freq[x]++;
        }
        
/*
        // dp[i] represents the money earned when i is the biggest element taken
        vector<int> dp(N), mx(N);
        
        for (int number = 1; number < N; number++) {
            
            dp[number] = freq[number] * number;
            
            // mx[number] = max(dp[1], dp[2], dp[number])
            if (number >= 2)
                dp[number] += mx[number - 2];
            
            mx[number] = max(dp[number], mx[number - 1]);
        }
        
        return mx[N - 1];
*/
        
        // dp[i] represents the money earned when i is the biggest element taken
        vector<int> dp(N);
        
        for (int number = 1; number < N; number++) {
            
            dp[number] = max(dp[number - 1], freq[number] * number + (number >= 2 ? dp[number - 2] : 0));
        }
        
        return dp[N - 1];
    }
};