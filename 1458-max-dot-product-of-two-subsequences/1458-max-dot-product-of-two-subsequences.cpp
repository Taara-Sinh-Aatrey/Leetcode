class Solution {
public:
    
    #define N 505

    vector<vector<int>> dp;
    const int inf = 1e9 + 5;
    
    int solve(vector<int>& nums1, vector<int>& nums2,int i,int j){
        if(i==0 || j==0 ){
            return -inf;
        }
        
        if (dp[i][j] > -inf)
            return dp[i][j];
        
        int op1 = nums1[i-1]*nums2[j-1] + max(0, solve(nums1,nums2,i-1,j-1));
        int op2 = solve(nums1,nums2,i,j-1);
        int op3 = solve(nums1,nums2,i-1,j);
        return dp[i][j] = max({op1,op2,op3});
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        dp.resize(N, vector<int>(N, -inf));
        return solve(nums1,nums2,nums1.size(),nums2.size());
    }
};

// class Solution {
// public:
//     int maxDotProduct(vector<int>& a, vector<int>& b) {
//         const int inf = 1e9 + 5;
//         int n = a.size(), m = b.size();
//         // dp[i][j] is the max dot product of two equal subseq of a and b when we have considered i elements of a and j elements of b
//         vector<vector<int>> dp(n + 1, vector<int>(m + 1, -inf));
        
//         for (int i = 1; i <= n; i++) {
//             for (int j = 1; j <= m; j++) {
//                 // a[i] * b[j]
//                 dp[i][j] = max({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1] + a[i - 1] * b[j - 1], 0 + a[i - 1] * b[j - 1]});
//             }
//         }
        
//         return dp[n][m];
//     }
// };