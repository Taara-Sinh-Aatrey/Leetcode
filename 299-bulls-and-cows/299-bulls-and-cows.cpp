class Solution {
public:
    string getHint(string secret, string guess) {
        string ans = "";
        int n = secret.size();
        assert(guess.size() == n);
        
        vector<int> cnt(10);
        int bulls = 0, cows = 0;
        for (int i = 0; i < n; i++) {
            int a = secret[i] - '0', b = guess[i] - '0';
            if (a == b)
                bulls++;
            else
                cows += (cnt[a]++ < 0) + (cnt[b]-- > 0);
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};