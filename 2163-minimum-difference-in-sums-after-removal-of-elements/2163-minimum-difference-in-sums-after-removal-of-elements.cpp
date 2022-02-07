class Solution {
public:
    long long minimumDifference(vector<int>& a) {
        #define int int64_t
        int n = a.size() / 3;
        int N = n * 3;
        vector<int> pref(N), suff(N);
        {
            priority_queue<int32_t> pq;
            int sum = 0;
            for (int i = 0; i < 2 * n; i++) {
                pq.emplace(a[i]);
                sum += a[i];
                if (pq.size() > n) {
                    sum -= pq.top();
                    pq.pop();
                }
                pref[i] = sum;
            }
        }
        
        {
            priority_queue<int32_t, vector<int32_t>, greater<int32_t>> pq;
            int sum = 0;
            for (int i = N - 1; i >= n; i--) {
                pq.emplace(a[i]);
                sum += a[i];
                if (pq.size() > n) {
                    sum -= pq.top();
                    pq.pop();
                }
                suff[i] = sum;
            }
        }
        int ans = LLONG_MAX;
        for (int i = n - 1; i < 2 * n; i++) {
            ans = min(ans, pref[i] - suff[i + 1]);
        }
        #undef int
        return ans;
    }
};