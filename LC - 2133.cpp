class Solution {
public:
    bool checkValid(vector<vector<int>>& m) {
        int n = m.size();
        for (int i = 0; i < n; ++i) {
            unordered_set<int> r, c;
            for (int j = 0; j < n; ++j) {
                r.insert(m[i][j]);
                c.insert(m[j][i]);
            }
            if (r.size() != n || c.size() != n) return false;
        }
        return true;
    }
};
