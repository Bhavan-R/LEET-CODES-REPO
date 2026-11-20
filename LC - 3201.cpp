class Solution {
public:
    int maximumLength(vector<int>& a) {
        int e = 0, o = 0, eo = 0, oe = 0;
        for (int x : a) {
            if (x % 2 == 0) {
                e++;
                eo = oe + 1;
            } else {
                o++;
                oe = eo + 1;
            }
        }
        return max({e, o, eo, oe});
    }
};
