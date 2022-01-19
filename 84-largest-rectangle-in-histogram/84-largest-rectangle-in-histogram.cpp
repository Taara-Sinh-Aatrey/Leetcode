class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int ans = 0, n = heights.size();
        stack<int> st;
        
        for (int i = 0; i <= n; i++) {
        
            while (!st.empty() && (i == n or heights[st.top()] >= heights[i])) {
                
                auto j = st.top();
                st.pop();
                
                ans = max(ans, (i - (st.empty() ? -1 : st.top()) - 1) * heights[j]);
                
            }
            
            st.emplace(i);
        }
        
        return ans;
    }
};