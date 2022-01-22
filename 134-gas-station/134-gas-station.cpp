class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        int sum = 0, minPref = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            sum += gas[i] - cost[i];
            minPref = min(minPref, sum);
        }
        
        if (minPref >= 0)
            return 0;
        
        int i = n - 1;
        while (i >= 0) {
            minPref = gas[i] - cost[i] + min(minPref, 0);
            
            if (minPref >= 0)
                break;
            
            i--;
        }
        
        return i;
    }
};