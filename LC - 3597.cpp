class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set<string> seen;
        vector<string> ans;
        string cur = "";
        
        for (char c : s) {
            cur += c;
            if (!seen.count(cur)) {
                seen.insert(cur);
                ans.push_back(cur);
                cur = "";
            }
        }
        
        return ans;
    }
};
