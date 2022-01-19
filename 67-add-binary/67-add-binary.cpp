class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string c;
        int sum = 0;
        for (int i = 0; i < a.size() || i < b.size() || sum > 0; i++) {
            sum += (i < a.size() ? a[i] - '0' : 0);
            sum += (i < b.size() ? b[i] - '0' : 0);
            c += char('0' + sum % 2);
            sum /= 2;
        }
        reverse(c.begin(), c.end());
        return c;
    }
};