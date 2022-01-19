class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        int n = path.size();
        for (int i = 0, j; i < n; i = j) {
            while (i < n && path[i] == '/') i++;
            if (i == n) break;
            j = i + 1;
            while (j < n && path[j] != '/') j++;
            string s = path.substr(i, j - i);
            if (s == "..") {
                if (!st.empty())
                    st.pop_back();
            }
            else if (s != ".") {
                st.emplace_back(s);
            }
        }
        string ans = "";
        for (auto &s : st) {
            ans += "/" + s;
        }
        if (ans.empty())
            ans = "/";
        return ans;
    }
};