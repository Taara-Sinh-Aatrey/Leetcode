class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact(n + 1, 1);
        for (int i = 2; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
        }
        
        vector<int> a(n);
        iota(a.begin(), a.end(), 1);
        string ans = "";
        for (int i = 0; i < n; i++) {
            int x = (k + fact[n - 1 - i] - 1) / fact[n - 1 - i];
            --x;
            k -= x * fact[n - 1 - i];
            assert(x >= 0 && x < n - i);
            ans += char('0' + a[x]);
            a.erase(a.begin() + x);
        }
        return ans;
    }
};