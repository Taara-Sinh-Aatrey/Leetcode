class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for (string &s : tokens) {
            int first, second;
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                second = st.top(); st.pop();
                first = st.top(); st.pop();
                if (s == "+")
                    st.emplace(first + second);
                else if (s == "-")
                    st.emplace(first - second);
                else if (s == "*")
                    st.emplace(first * second);
                else
                    st.emplace(first / second);
            }
            else {
                st.emplace(stoi(s));
            }
        }
        assert(st.size() == 1);
        return st.top();
    }
};