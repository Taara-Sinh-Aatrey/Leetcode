class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        vector<string> strs;
        for (int &x : nums)
            strs.emplace_back(to_string(x));
        
        sort(strs.begin(), strs.end(), [&] (auto &s, auto &t) {
            return s + t > t + s;
        });
        
        string ans = "";
        for (string &s : strs)
            ans += s;
        
        if (*max_element(ans.begin(), ans.end()) == '0')
            ans = "0";
        
        return ans;
    }
};