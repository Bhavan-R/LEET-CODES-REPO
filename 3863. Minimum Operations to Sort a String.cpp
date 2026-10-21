#include <string>
#include <algorithm>

class Solution {
public:
    int minOperations(std::string s) {
        int n = s.length();

        bool sorted = true;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] > s[i + 1]) {
                sorted = false;
                break;
            }
        }
        if (sorted) return 0;

        if (n == 2) return -1;

        char mn = s[0], mx = s[0];
        for (char c : s) {
            mn = std::min(mn, c);
            mx = std::max(mx, c);
        }

        if (s[0] == mn || s[n - 1] == mx) {
            return 1;
        }

        bool max_only_at_first = (s[0] == mx);
        for (int i = 1; i < n; ++i) {
            if (s[i] == mx) {
                max_only_at_first = false;
                break;
            }
        }

        bool min_only_at_last = (s[n - 1] == mn);
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == mn) {
                min_only_at_last = false;
                break;
            }
        }

        if (max_only_at_first && min_only_at_last) {
            return 3;
        }

        return 2;
    }
};
