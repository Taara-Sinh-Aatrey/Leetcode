class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> g(n);
        vector<int> indeg(n);
        for (auto &pr : pre) {
            int u = pr[1], v = pr[0];
            g[u].emplace_back(v);
            indeg[v]++;
        }
        
        vector<int> taken;
        
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                q.emplace(i);
                taken.emplace_back(i);
            }
        }
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (auto &v : g[u]) {
                indeg[v]--;
                if (indeg[v] == 0) {
                    q.emplace(v);
                    taken.emplace_back(v);
                }
            }
        }
        
        if (taken.size() < n)
            taken.clear();
        return taken;
    }
};