class Solution {
public:
    int reverseDegree(string s) {
        int total = 0;
        for (int i = 0; i < s.length(); ++i) {
            total += (26 - (s[i] - 'a')) * (i + 1);
        }
        return total;
    }
};
