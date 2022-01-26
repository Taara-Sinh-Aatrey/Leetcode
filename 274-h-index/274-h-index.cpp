class Solution {
public:
    int hIndex(vector<int>& a) {
        int ans = 0, n = a.size();
        
        sort(a.rbegin(), a.rend());
        
        for (int i = 0; i < n; i++)
            if (a[i] >= i + 1 && (i == n - 1 || a[i + 1] <= i + 1))
                ans = i + 1;
        
        return ans;
    }
};