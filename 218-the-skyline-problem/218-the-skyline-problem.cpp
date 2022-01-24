class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
        set<int> endPoints;
        map<int, vector<pair<int, int>>> mp;
        for (auto &pr : buildings) {
            endPoints.emplace(pr[0]);
            endPoints.emplace(pr[1]);
            mp[pr[0]].emplace_back(pr[1], pr[2]);
        }
        
        set<pair<int, int>> st;
        
        vector<vector<int>> ans;
        
        for (auto &x : endPoints) {
            
            while (!st.empty() && st.begin()->first <= x) {
                st.erase(st.begin());
            }
            
            for (auto [y, h] : mp[x]) {
                st.emplace(y, h);
                auto it = prev(st.lower_bound({y, INT_MAX}));
                auto jt = it;
                while (jt != st.begin() && prev(jt)->second <= it->second) {
                    jt = prev(jt);
                }
                if (it != st.end() && next(it)->second >= it->second)
                    it = next(it);
                st.erase(jt, it);
            }
            
            ans.push_back({x, st.empty() ? 0 : st.begin()->second});
            
        }
        
        vector<vector<int>> nans;
        for (int i = 0; i < ans.size(); i++) {
            if (nans.empty() || nans.back()[1] != ans[i][1]) {
                nans.emplace_back(ans[i]);
            }
        }
        
        return nans;
    }
};