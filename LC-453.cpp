class Solution {
public:
    int minMoves(vector<int>& nums) {
        int m = nums[0];
        long s = 0;
        for (int x : nums) {
            if (x < m) m = x;
            s += x;
        }
        return s - (long)m * nums.size();
    }
};
