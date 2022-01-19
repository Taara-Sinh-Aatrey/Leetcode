class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m - 1 + n - 1;
        int M = min(m - 1, n - 1);
        // C(N, 0)
        int ans = 1;
        for (int i = 1; i <= M; i++) {
            // C(N, i) = C(N, i - 1) * (N - i + 1) / i;
            ans = ans * 1LL * (N - i + 1) / i;
        }
        return ans;
    }
};