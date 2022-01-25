class Solution {
public:
    bool isUgly(int n) {
        
        for (auto &x : {2, 3, 5}) {
            while (n > 0 && n % x == 0)
                n /= x;
        }
        
        return n == 1;
    }
};