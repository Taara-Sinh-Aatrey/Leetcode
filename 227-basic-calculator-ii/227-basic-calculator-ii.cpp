class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        stack<int> st;
        
        for (int i = 0; i < n; ) {
            
            // ignore spaces
            while (i < n && s[i] == ' ') i++;
            
            // fetch the operator
            char op = '+';
            if (s[i] == '*' || s[i] == '/' || s[i] == '-' || s[i] == '+')
                op = s[i++];
            
            // ignore spaces
            while (i < n && s[i] == ' ') i++;
            
            // fetch the next operand
            int j = i, num = 0;
            while (j < n && '0' <= s[j] && s[j] <= '9')
                num = num * 10 + (s[j++] - '0');

            i = j;
            
            if (op == '-')
                num *= -1;
            
            if (op == '*') {
                num *= st.top();
                st.pop();
            }
            else if (op == '/') {
                num = st.top() / num;
                st.pop();
            }
            
            st.emplace(num);
        }
        
        int ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};