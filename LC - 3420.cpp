class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0, ops = 0;
        deque<int> dq;
        
        for (int l = n - 1, r = n - 1; l >= 0; --l) {
            while (!dq.empty() && nums[dq.back()] < nums[l]) {
                int idx = dq.back();
                dq.pop_back();
                int nextIdx = dq.empty() ? r + 1 : dq.back();
                ops += 1LL * (nums[l] - nums[idx]) * (nextIdx - idx);
            }
            dq.push_back(l);
            
            while (ops > k) {
                ops -= (nums[dq.front()] - nums[r]);
                if (dq.front() == r) dq.pop_front();
                r--;
            }
            ans += (r - l + 1);
        }
        return ans;
    }
};
