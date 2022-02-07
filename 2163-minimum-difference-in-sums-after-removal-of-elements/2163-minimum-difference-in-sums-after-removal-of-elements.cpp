class Solution {
public:
    long long minimumDifference(vector<int>& a) {
        #define int int64_t
        int n = a.size() / 3;
        int N = n * 3;
        vector<int> pref(n + 1), suff(n + 1);
        multiset<int32_t> cur;
        int sum = 0;
        for (int i = 0; i < 2 * n; i++) {
            cur.insert(a[i]);
            sum += a[i];
            if (cur.size() > n) {
                sum -= *cur.rbegin();
                cur.erase(prev(cur.end()));
            }
            if (i >= n - 1)
                pref[i - (n  - 1)] = sum;
        }
        
        cur.clear();
        sum = 0;
        for (int i = N - 1; i >= n; i--) {
            cur.insert(a[i]);
            sum += a[i];
            if (cur.size() > n) {
                sum -= *cur.begin();
                cur.erase(cur.begin());
            }
            if (i <= N - n)
                suff[i - n] = sum;
        }
        int ans = LLONG_MAX;
        for (int i = n - 1; i < 2 * n; i++) {
            ans = min(ans, pref[i - (n  - 1)] - suff[i + 1 - n]);
        }
        #undef int
        return ans;
    }
};