class Solution {
    int time_cnt;
    vector<int> tin, tout, depth;
    vector<vector<int>> up;
    vector<vector<int>> adj;
    vector<int> bit;
    int sz;

    void add(int i, int val) {
        for (; i <= sz; i += i & -i) bit[i] ^= val;
    }

    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) sum ^= bit[i];
        return sum;
    }

    void dfs(int u, int p, int d, const string& s) {
        tin[u] = ++time_cnt;
        depth[u] = d;
        up[u][0] = p;
        for (int i = 1; i < 18; ++i) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }

        int mask = 1 << (s[u] - 'a');
        add(tin[u], mask);

        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u, d + 1, s);
            }
        }
        tout[u] = time_cnt;
        add(tout[u] + 1, mask);
    }

    int get_lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        for (int i = 17; i >= 0; --i) {
            if (depth[u] - (1 << i) >= depth[v]) {
                u = up[u][i];
            }
        }
        if (u == v) return u;
        for (int i = 17; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

    int get_node_mask(int u) {
        return query(tin[u]);
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        adj.assign(n, vector<int>());
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        time_cnt = 0;
        tin.resize(n);
        tout.resize(n);
        depth.resize(n);
        up.assign(n, vector<int>(18, 0));
        sz = n + 2;
        bit.assign(sz + 1, 0);

        dfs(0, 0, 0, s);

        vector<bool> res;

        for (const auto& q_str : queries) {
            stringstream ss(q_str);
            string type;
            ss >> type;
            if (type == "update") {
                int node;
                char c;
                ss >> node >> c;
                int old_mask = 1 << (s[node] - 'a');
                int new_mask = 1 << (c - 'a');
                int diff = old_mask ^ new_mask;
                s[node] = c;

                add(tin[node], diff);
                add(tout[node] + 1, diff);
            } else {
                int u, v;
                ss >> u >> v;
                int lca = get_lca(u, v);
                int path_mask = get_node_mask(u) ^ get_node_mask(v) ^ (1 << (s[lca] - 'a'));
                
                int set_bits = __builtin_popcount(path_mask);
                res.push_back(set_bits <= 1);
            }
        }

        return res;
    }
};
