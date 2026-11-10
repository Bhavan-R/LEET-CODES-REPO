#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, 0);

        for (int j = 1; j <= n; ++j) {
            int min_cost = INT_MAX;
            for (int k = 1; k <= 3; ++k) {
                if (j - k >= 0) {
                    int current_cost = dp[j - k] + costs[j - 1] + k * k;
                    min_cost = min(min_cost, current_cost);
                }
            }
            dp[j] = min_cost;
        }

        return dp[n];
    }
};
