class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> fS, fT;
        for (char &ch : s)
            fS[ch]++;
        
        for (char &ch : t)
            fT[ch]++;
        
        return fS == fT;
    }
};