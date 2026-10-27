class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> count(100, 0);
        vector<int> ans;
        
        for (int num : nums) {
            count[num]++;
            if (count[num] == 2) {
                ans.push_back(num);
            }
        }
        
        return ans;
    }
};
