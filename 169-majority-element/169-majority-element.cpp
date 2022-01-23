class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cur, c = 0;
        for (int &x : nums) {
            if (c == 0)
                cur = x, c = 1;
            else if (cur == x)
                c++;
            else
                c--;
        }
        return cur;
    }
};