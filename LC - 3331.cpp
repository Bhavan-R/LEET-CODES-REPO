class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& p, string s) {
        int n = p.size();
        vector<vector<int>> g(n);
        for (int i = 1; i < n; ++i) {
            g[p[i]].push_back(i);
        }
        
        vector<int> np = p;
        vector<int> ls(26, -1);
        
        auto f = [&](auto& self, int u) -> void {
            int c = s[u] - 'a';
            int prev = ls[c];
            
            if (prev != -1) {
                np[u] = prev;
            }
            
            ls[c] = u;
            for (int v : g[u]) {
                self(self, v);
            }
            ls[c] = prev;
        };
        
        f(f, 0);
        
        vector<vector<int>> ng(n);
        for (int i = 1; i < n; ++i) {
            ng[np[i]].push_back(i);
        }
        
        vector<int> a(n, 1);
        auto d = [&](auto& self, int u) -> void {
            for (int v : ng[u]) {
                self(self, v);
                a[u] += a[v];
            }
        };
        
        d(d, 0);
        return a;
    }
};
