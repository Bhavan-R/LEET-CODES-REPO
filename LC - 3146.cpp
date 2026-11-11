class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int pos[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            pos[s[i] - 'a'] = i;
        }
        
        int diff = 0;
        for (int i = 0; i < t.length(); i++) {
            diff += abs(pos[t[i] - 'a'] - i);
        }
        
        return diff;
    }
};
