class Solution {
public:
    int minNumber(vector<int>& a, vector<int>& b) {
        int c = 10, d = 10, e = 10;
        int f[10] = {0}, g[10] = {0};
        
        for (int x : a) {
            f[x] = 1;
            c = min(c, x);
        }
        
        for (int x : b) {
            g[x] = 1;
            d = min(d, x);
        }
        
        for (int i = 1; i <= 9; ++i) {
            if (f[i] && g[i]) {
                e = min(e, i);
            }
        }
        
        if (e != 10) return e;
        
        return min(c, d) * 10 + max(c, d);
    }
};
