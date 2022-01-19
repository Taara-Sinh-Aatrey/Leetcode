class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int i = n - 1;
        while (i >= 0 && digits[i] == 9) i--;
        if (i == n - 1) {
            digits[i]++;
            return digits;
        }
        digits.resize(i + 1);
        if (digits.empty())
            digits.emplace_back(1);
        else
            digits.back()++;
        i++;
        while (i < n) {
            digits.emplace_back(0);
            i++;
        }
        return digits;
    }
};