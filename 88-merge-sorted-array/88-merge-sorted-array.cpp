class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        vector<int> nums3(n + m);
        int i = 0, j = 0, k = 0;;
        while (i < n || j < m) {
            if (j >= m || (i < n && nums1[i] < nums2[j])) {
                nums3[k++] = nums1[i++];
            }
            else {
                nums3[k++] = nums2[j++];
            }
        }
        nums1 = nums3;
    }
};