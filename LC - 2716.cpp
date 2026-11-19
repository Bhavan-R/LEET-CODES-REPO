class Solution {
public:
    int minimizedStringLength(string s) {
        unordered_set<char> u(s.begin(), s.end());
        return u.size();
    }
};
