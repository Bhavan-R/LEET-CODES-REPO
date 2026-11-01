class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        
        int l = 0, r = n - 1, p1 = n;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] >= 0) {
                p1 = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        
        l = 0; r = n - 1;
        int p2 = n;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] > 0) {
                p2 = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        
        int neg = p1;
        int pos = n - p2;
        
        return max(neg, pos);
    }
};
