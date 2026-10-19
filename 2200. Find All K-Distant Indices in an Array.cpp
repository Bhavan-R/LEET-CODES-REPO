class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> result;
        int n = nums.size();
        int lastAdded = -1;

        for (int j = 0; j < n; j++) {
            if (nums[j] == key) {
                int start = max(lastAdded + 1, j - k);
                int end = min(n - 1, j + k);

                for (int i = start; i <= end; i++) {
                    result.push_back(i);
                }
                
                lastAdded = end;
            }
        }

        return result;
    }
};
