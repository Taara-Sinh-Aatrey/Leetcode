class Solution {
public:
    
    void generateIp(string &s, int idx, int wordsTaken, string &curSol, vector<string> &res) {
        
        if (wordsTaken == 4 && idx == s.size()) {
            res.emplace_back(curSol);
            return;
        }
        
        if (wordsTaken == 4 || idx == s.size())
            return;
        
        int num = 0;
        string cur;
        
        for (int i = 0; i < 3 && idx + i < s.size(); i++) {
            
            cur += s[idx + i];
            num = num * 10 + s[idx + i] - '0';
            if (num > 255) {
                break;
            }
            
            curSol += cur;
            if (wordsTaken < 3)
                curSol += ".";
            
            generateIp(s, idx + i + 1, wordsTaken + 1, curSol, res);
            
            if (wordsTaken < 3)
                curSol.pop_back();
            for (int x = 0; x < i + 1; x++)
                curSol.pop_back();
            
            if (s[idx] == '0')
                break;
        }
        
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string curSol;
        generateIp(s, 0, 0, curSol, res);
        return res;
    }
};