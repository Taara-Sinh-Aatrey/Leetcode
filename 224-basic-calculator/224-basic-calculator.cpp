class Solution {
public:
    
    int eval (string &s, vector<int>& match, int low, int high) {
        int val = 0;
        
        char prv = '+';
        
        for (int x = low; x <= high;) {
            
            if (s[x] == ' ') {
                x++;
                continue;
            }
            else if (s[x] == '+' || s[x] == '-') {
                prv = s[x++];
                continue;
            }
            
            int z = 0;
            if (s[x] == '(') {
                int y = match[x];
                z = eval(s, match, x + 1, y - 1);
                x = y + 1;
            }
            else {
                int y = x;
                while (y <= high && '0' <= s[y] && s[y] <= '9')
                    z = z * 10 + (s[y++] - '0');
                x = y;
            }
            
            val += (prv == '+' ? 1 : -1) * z;
        }
        
        return val;
    } 
    
    int calculate(string s) {
        int n = s.size();
        
        stack<int> st;
        vector<int> match(n, -1);
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.emplace(i);
            }
            else if (s[i] == ')') {
                match[st.top()] = i;
                match[i] = st.top();
                st.pop();
            }
        }
        
        return eval(s, match, 0, n - 1);
    }
};