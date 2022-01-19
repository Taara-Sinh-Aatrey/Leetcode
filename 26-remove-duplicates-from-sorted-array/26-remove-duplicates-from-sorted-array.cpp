class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        int next_empty_index = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                // ith element is a new element
                nums[next_empty_index++] = nums[i];
            }
        }
        
        return next_empty_index;
    }
};