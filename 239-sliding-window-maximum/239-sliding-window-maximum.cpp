class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        
        for (int i = 0; i < nums.size(); i++) {
            
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            
            dq.emplace_back(i);
            
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();
            
            if (i >= k - 1)
                ans.emplace_back(nums[dq.front()]);
        }
        
        return ans;
    }
};