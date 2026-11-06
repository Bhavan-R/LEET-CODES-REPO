#include <vector>

using namespace std;

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> diff(52, 0);
        
        for (const auto& range : ranges) {
            diff[range[0]]++;
            diff[range[1] + 1]--;
        }

        int current = 0;
        for (int i = 1; i <= right; ++i) {
            current += diff[i];
            if (i >= left && current <= 0) {
                return false;
            }
        }

        return true;
    }
};
