class Solution {
public:
    int hIndex(vector<int>& a) {
        int n = a.size();
        
        int low = 1, high = n;
        while (low <= high) {
            int mid = (low + high) / 2;
            
            if (a[n - mid] >= mid)
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        return high;
    }
};