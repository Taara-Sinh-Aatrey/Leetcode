class Solution {
public:
    int maximalRectangle(vector<vector<char>>& A) {
        int n = A.size(), m = A[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        for (int j = 0; j < m; j++) {
            for (int i = n - 1; i >= 0; i--) {
                if (A[i][j] == '0')
                    dp[i][j] = 0;
                else
                    dp[i][j] = 1 + (i + 1 < n ? dp[i + 1][j] : 0);
            }
        }
        
        int ans = 0;
        
        for (auto &row : dp) {
            stack<int> st;
            vector<int> left(m);
            for (int j = 0; j < m; j++) {
                while (!st.empty() && row[st.top()] >= row[j]) {
                    st.pop();
                }
            
                left[j] = st.empty() ? -1 : st.top();
                st.push(j);
            }
            while (!st.empty()) {
                st.pop();
            }
            
            vector<int> right(m);
            for (int j = m - 1; j >= 0; j--) {
                while (!st.empty() && row[st.top()] >= row[j]) {
                    st.pop();
                }
                
                right[j] = st.empty() ? m : st.top();
                st.push(j);
            }
            
            for (int j = 0; j < m; j++) {
                int cur = row[j] * (right[j] - left[j] - 1);
                // cout << j << " " << row[j] << " " << left[j] << " " << right[j] << " " << cur << endl;
                ans = max(ans, cur);
            }
            // cout << "----------------------------------" << endl;
        }
        
        return ans;
        
        
    }
};