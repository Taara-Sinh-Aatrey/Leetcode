class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.size(), n2 = version2.size();
        
        int l1 = 0, l2 = 0;
        while (l1 < n1 || l2 < n2) {
            
            int val1 = 0;
            while (l1 < n1 && version1[l1] != '.')
                val1 = val1 * 10 + (version1[l1++] - '0');
            
            int val2 = 0;
            while (l2 < n2 && version2[l2] != '.')
                val2 = val2 * 10 + (version2[l2++] - '0');
            
            ++l1, ++l2;
            
            if (val1 < val2)
                return -1;
            else if (val1 > val2)
                return 1;
        }
        
        return 0;
    }
};