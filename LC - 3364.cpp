class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size(), m = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int s = 0;
            for (int j = i; j < n; ++j) {
                s += nums[j];
                int k = j - i + 1;
                if (k >= l && k <= r && s > 0) m = min(m, s);
            }
        }
        return m == INT_MAX ? -1 : m;
    }
};
