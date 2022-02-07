class Solution {
public:
    long long minimumDifference(vector<int>& a) {
        #define int int64_t
        int n = a.size() / 3;
        int N = n * 3;
        vector<int> pref(N), suff(N);
        multiset<int> cur;
        int sum = 0;
        for (int i = 0; i < N; i++) {
            cur.insert(a[i]);
            sum += a[i];
            if (cur.size() > n) {
                sum -= *cur.rbegin();
                cur.erase(prev(cur.end()));
            }
            pref[i] = sum;
        }
        
        cur.clear();
        sum = 0;
        for (int i = N - 1; i >= 0; i--) {
            cur.insert(a[i]);
            sum += a[i];
            if (cur.size() > n) {
                sum -= *cur.begin();
                cur.erase(cur.begin());
            }
            suff[i] = sum;
        }
        int ans = LLONG_MAX;
        for (int i = n - 1; i < 2 * n; i++) {
            ans = min(ans, pref[i] - suff[i + 1]);
        }
        #undef int
        return ans;
    }
};