class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = -1, num2 = -1;
        int count1 = 0, count2 = 0;
        int n = nums.size();
        
        for (auto &num : nums) {
            if (num == num1) { 
                count1++; 
            }
            else if (num == num2) { 
                count2++; 
            }
            else if (count1 == 0) {
                num1 = num;
                count1 = 1;
            }
            else if (count2 == 0) {
                num2 = num;
                count2 = 1;
            }
            else {
                count1--, count2--;
            }
        }
        
        int ct1 = 0, ct2 = 0;
        for (auto &num : nums) {
            if(num == num1) { 
                ct1++; 
            }
            else if (num == num2) { 
                ct2++; 
            }
        }
        
        vector<int> res;
        if (ct1 > n / 3) {
            res.emplace_back(num1);
        } 
        if (ct2 > n / 3) {
            res.emplace_back(num2);
        }
        
        return res;
    }
};