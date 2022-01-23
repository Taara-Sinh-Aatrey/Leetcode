class Solution {
public:
    string fractionToDecimal(int num, int den) {
        bool neg = num && ((num < 0) ^ (den < 0));
        long long numerator = num < 0 ? -1LL * num : num;
        long long denominator = den < 0 ? -1LL * den : den;
        unordered_map<int, int> idx;
        string ans = to_string(numerator / denominator);
        numerator %= denominator;
        ans += '.';
        while (numerator) {
            numerator *= 10;
            if (idx.count(numerator)) {
                ans.insert(ans.begin() + idx[numerator], '(');
                ans += ')';
                break;
            }
            idx[numerator] = ans.size();
            ans += char('0' + numerator / denominator);
            numerator %= denominator;
        }
        if (ans.back() == '.')
            ans.pop_back();
        if (neg)
            ans = "-" + ans;
        return ans;
    }
};