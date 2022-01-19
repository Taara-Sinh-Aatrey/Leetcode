class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums.size();
        
        int next_empty_index = 2;
        
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[next_empty_index - 2]) {
                nums[next_empty_index++] = nums[i];
            }
        }
        
        return next_empty_index;  
    }
};