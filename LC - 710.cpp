class Solution {
private:
    int sz;
    unordered_map<int, int> mapping;

public:
    Solution(int n, vector<int>& blacklist) {
        sz = n - blacklist.size();
        unordered_set<int> w;
        for (int i = sz; i < n; ++i) {
            w.insert(i);
        }
        for (int x : blacklist) {
            w.erase(x);
        }
        auto it = w.begin();
        for (int x : blacklist) {
            if (x < sz) {
                mapping[x] = *it;
                ++it;
            }
        }
    }

    int pick() {
        int idx = rand() % sz;
        if (mapping.count(idx)) {
            return mapping[idx];
        }
        return idx;
    }
};
