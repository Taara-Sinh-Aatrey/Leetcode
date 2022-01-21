class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans[n];
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                bool ok = true;
                for (int x = i, y = j; x < y; x++, y--) {
                    if (s[x] != s[y]) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) continue;
                if (i == 0) {
                    ans[j].push_back({s.substr(i, j - i + 1)});
                }
                else {
                    for (auto &vec : ans[i - 1]) {
                        vec.emplace_back(s.substr(i, j - i + 1));
                        ans[j].emplace_back(vec);
                        vec.pop_back();
                    }
                }
            }
        }
        return ans[n - 1];
    }
};