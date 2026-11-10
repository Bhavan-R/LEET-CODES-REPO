class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> s;
        int p = 0;
        int m = nums[0];

        for (int x : nums) {
            m = max(m, x);
            if (x > 0 && !s.count(x)) {
                p += x;
                s.insert(x);
            }
        }

        if (p == 0 && m <= 0) {
            return m;
        }

        return p;
    }
};
