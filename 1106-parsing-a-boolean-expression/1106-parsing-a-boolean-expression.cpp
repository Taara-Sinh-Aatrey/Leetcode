class Solution {
public:
    bool parseBoolExpr(string s) {
        int n = s.size();
        
        stack<char> st;
        
        // &(t,!(|(f, t)))
        
        auto getVal = [&] (char ch) -> bool {
            return ch == 't';    
        };
        
        auto getChar = [&] (int val) -> char {
            if (val)
                return 't';
            return 'f';
        };
        
        for (int i = 0; i < n; i++) {
            if (s[i] == ')') {
                vector<char> save;
                while (st.top() != '(') {
                    save.emplace_back(st.top());
                    st.pop();
                }
                st.pop();
                char op = st.top();
                st.pop();
                int res;
                if (op == '!') {
                    assert(save.size() == 1);
                    res = !getVal(save[0]);
                }
                else {
                    res = (op == '|' ? 0 : 1);
                    for (auto &ch : save) {
                        if (op == '|') {
                            res |= getVal(ch);
                        }
                        else {
                            res &= getVal(ch);
                        }
                    }
                }
                st.emplace(getChar(res));
            }
            else if (s[i] != ',') {
                st.emplace(s[i]);
            }
        }
        assert(st.size() == 1);
        return getVal(st.top());
    }
};