class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int mW) {
        vector<string> ans;
        int n = words.size();
        for (int i = 0, j = 0; i < n; i = j) {
            j = i + 1;
            int w = words[i].size();
            while (j < n && w + 1 + words[j].size() <= mW) {
                w += 1 + words[j].size();
                j++;
            }
            int cnt = j - i;
            string cur;
            if (cnt == 1 || j == n) {
                for (int x = i; x < j; x++) {
                    if (x != i) {
                        cur += ' ';
                    }
                    cur += words[x];
                }
                cur += string(mW - cur.size(), ' ');
            }
            else {
                int gap = mW - w;
                int each = 1 + gap / (cnt - 1);
                int extra = gap % (cnt - 1);
                for (int x = 0; x < cnt - 1; x++) {
                    cur += words[i + x] + string(each + (x < extra ? 1 : 0), ' ');
                }
                cur += words[i + cnt - 1];
                assert(cur.size() == mW);
            }
            ans.emplace_back(cur);
        }
        return ans;
    }
};