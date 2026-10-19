class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int count = 0;
        int lessThan = 0;

        for (int num : nums) {
            if (num == target) {
                count++;
            } else if (num < target) {
                lessThan++;
            }
        }

        vector<int> result;
        for (int i = 0; i < count; i++) {
            result.push_back(lessThan + i);
        }

        return result;
    }
};
