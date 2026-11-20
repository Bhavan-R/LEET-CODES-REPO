class Solution {
public:
    int maxSelectedElements(vector<int>& a) {
        sort(a.begin(), a.end());
        unordered_map<int, int> d;
        int m = 0;
        for (int x : a) {
            d[x + 1] = d[x] + 1;
            d[x] = d[x - 1] + 1;
            m = max({m, d[x], d[x + 1]});
        }
        return m;
    }
};
