class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        int pairs = 0;
        for (auto& [num, count] : freq) {
            if (k > 0 && freq.count(num + k)) {
                pairs++;
            } else if (k == 0 && count > 1) {
                pairs++;
            }
        }
        
        return pairs;
    }
};
