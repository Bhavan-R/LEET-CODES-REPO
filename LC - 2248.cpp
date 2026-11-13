class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int count[1001] = {0};
        int n = nums.size();
        
        for (const auto& arr : nums) {
            for (int x : arr) {
                count[x]++;
            }
        }
        
        vector<int> result;
        for (int i = 1; i <= 1000; ++i) {
            if (count[i] == n) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};
