class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        map<string, int> freq;
        for (int i = 0; i + 10 <= s.size(); i++)
            freq[s.substr(i, 10)]++;
        
        vector<string> ans;
        for (auto &[s, cnt] : freq)
            if (cnt > 1)
                ans.emplace_back(s);
        
        return ans;
    }
};