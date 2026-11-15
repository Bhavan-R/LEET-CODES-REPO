class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int m = 1e9 + 7;
        long long o = 0, e = 1, t = 0;
        int s = 0;

        for (int x : arr) {
            s += x;
            if (s % 2 == 1) {
                t = (t + e) % m;
                o++;
            } else {
                t = (t + o) % m;
                e++;
            }
        }

        return t;
    }
};
