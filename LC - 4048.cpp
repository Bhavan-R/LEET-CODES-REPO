class Solution {
public:
    int countSpecialIntegers(vector<int>& a) {
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < a.size(); ++i) m[a[i]].push_back(i);
        int c = 0;
        for (auto& [x, v] : m)
            if (v.size() == 3 && v[1] - v[0] == v[2] - v[1]) ++c;
        return c;
    }
};
