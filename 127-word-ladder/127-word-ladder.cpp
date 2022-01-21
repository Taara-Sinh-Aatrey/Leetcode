class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        sort(wordList.begin(), wordList.end());
        map<string, int> ans;
        ans[beginWord] = 1;
        
        queue<pair<string, int>> q;
        q.emplace(beginWord, 1);
        
        while (!q.empty()) {
            
            auto [s, d] = q.front();
            q.pop();
            
            for (int i = 0; i < s.size(); i++) {
                char ch = s[i];
                
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    
                    s[i] = ch;
                    
                    if (!binary_search(wordList.begin(), wordList.end(), s))
                        continue;
                    
                    if (!ans.count(s)) {
                        ans[s] = d + 1;
                        q.emplace(s, d + 1);
                    }
                    
                }
                
                s[i] = ch;
            }
            
        }
        
        return ans[endWord];
    }
};