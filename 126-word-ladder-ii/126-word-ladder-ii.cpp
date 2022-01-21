class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        sort(wordList.begin(), wordList.end());

        map<string, vector<vector<string>>> ans;
        ans[beginWord] = {{beginWord}};
        
        queue<pair<string, int>> q;
        q.emplace(beginWord, 1);
        
        while (!q.empty()) {
            
            auto [s, d] = q.front();
            q.pop();
            
            auto &vv = ans[s];
            
            for (int i = 0; i < s.size(); i++) {
                char ch = s[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    s[i] = ch;
                    if (!binary_search(wordList.begin(), wordList.end(), s))
                        continue;
                    
                    if (!ans[s].empty() && ans[s][0].size() < d + 1)
                        continue;
                    
                    if (ans[s].empty())
                        q.emplace(s, d + 1);
                    
                    for (auto &v : vv) {
                        v.emplace_back(s);
                        ans[s].emplace_back(v);
                        v.pop_back();
                    }
                }
                s[i] = ch;
            }
            
        }
        
        return ans[endWord];
    }
};