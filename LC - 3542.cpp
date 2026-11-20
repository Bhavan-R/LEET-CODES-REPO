class Solution {
public:
    int minOperations(vector<int>& a) {
        vector<int> s;
        int c = 0;
        for (int x : a) {
            while (!s.empty() && s.back() > x) {
                s.pop_back();
            }
            if (x > 0 && (s.empty() || s.back() < x)) {
                s.push_back(x);
                c++;
            }
        }
        return c;
    }
};
