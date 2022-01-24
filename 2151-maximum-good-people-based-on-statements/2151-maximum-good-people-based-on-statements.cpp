class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size();
        int ans = 0;
        for (int mask = 0; mask < 1 << n; mask++) {
            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (!(mask >> i & 1))
                    continue;
                for (int j = 0; j < n; j++) {
                    if (j == i || statements[i][j] == 2)
                        continue;
                    if ((mask >> j & 1) != statements[i][j])
                        ok = false;
                }
            }
            if (!ok)
                continue;
            ans = max(ans, __builtin_popcount(mask));                
        }
        return ans;
    }
};