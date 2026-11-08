class Solution {
public:
    int residuePrefixes(string s) {
        unordered_set<char> distinct;
        int count = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            distinct.insert(s[i]);
            int prefixLen = i + 1;
            if (distinct.size() == prefixLen % 3) {
                count++;
            }
        }
        
        return count;
    }
};
