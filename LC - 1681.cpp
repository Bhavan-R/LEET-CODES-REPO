class Solution {
public:
    int minimumIncompatibility(vector<int>& a, int k) {
        int n = a.size(), m = n / k, M = 1 << n, I = 1e9;
        vector<int> f(n + 1);
        for (int x : a) if (++f[x] > k) return -1;
        sort(a.begin(), a.end());
        
        vector<int> c(M, -1), d(M, I);
        for (int s = 0; s < M; ++s) {
            if (__builtin_popcount(s) != m) continue;
            int p = -1, l = I, h = -1;
            for (int i = 0; i < n; ++i) {
                if (s & (1 << i)) {
                    if (a[i] == p) { l = -1; break; }
                    p = a[i]; l = min(l, a[i]); h = max(h, a[i]);
                }
            }
            if (l != -1) c[s] = h - l;
        }
        
        d[0] = 0;
        for (int s = 0; s < M; ++s) {
            if (d[s] == I) continue;
            int r = (M - 1) ^ s, b = r & -r;
            for (int u = r; u; u = (u - 1) & r)
                if ((u & b) && c[u] != -1) d[s | u] = min(d[s | u], d[s] + c[u]);
        }
        return d[M - 1] == I ? -1 : d[M - 1];
    }
};
