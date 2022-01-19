class Solution {
public:
    int maximalRectangle(vector<vector<char>>& A) {
        int n = A.size(), m = A[0].size();
        
        // dp[i][j] denotes the number of consecutive ones below (i, j) starting from (i, j)
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
            
            // left[j] = k, is the closest element to the left of j such that row[k] < row[j]
            vector<int> left(m);
            for (int j = 0; j < m; j++) {
                
                // get rid of all the equal or larger elements for we need the smaller element to the left
                while (!st.empty() && row[st.top()] >= row[j]) {
                    st.pop();
                }
            
                left[j] = st.empty() ? -1 : st.top();
                st.push(j);
            }
            
            // empty the stack for further usage
            while (!st.empty()) {
                st.pop();
            }
            
            // right[j] = k, is the closest element to the right of j such that row[k] < row[j]
            vector<int> right(m);
            for (int j = m - 1; j >= 0; j--) {
                
                // get rid of all the equal or larger elements for we need the smaller element to the left
                while (!st.empty() && row[st.top()] >= row[j]) {
                    st.pop();
                }
                
                right[j] = st.empty() ? m : st.top();

                st.push(j);
            }
            
            for (int j = 0; j < m; j++) {
                
                // height of the rectangle is row[j]
                // width of the rectangle is right[j] - left[j] - 1 
                // both right[j] and left[j] are not included
                int cur = row[j] * (right[j] - left[j] - 1);
                ans = max(ans, cur);
            }
        }
        
        return ans;
        
        
    }
};