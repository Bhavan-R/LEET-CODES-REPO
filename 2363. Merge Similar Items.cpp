class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> mp;
        for (const auto& item : items1) {
            mp[item[0]] += item[1];
        }
        for (const auto& item : items2) {
            mp[item[0]] += item[1];
        }
        
        vector<vector<int>> ret;
        for (const auto& [value, weight] : mp) {
            ret.push_back({value, weight});
        }
        return ret;
    }
};
