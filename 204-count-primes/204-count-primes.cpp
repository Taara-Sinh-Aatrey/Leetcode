class Solution {
public:
    int countPrimes(int n) {
        if (n == 0)
            return 0;
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        int cnt = 0;
        for (int i = 2; i < n; i++) {
            if (!isPrime[i])
                continue;
            cnt++;
            for (int64_t j = i * 1LL * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
        return cnt;
    }
};