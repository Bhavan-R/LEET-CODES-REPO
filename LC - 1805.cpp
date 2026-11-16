class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> s;
        int n = word.length();
        
        for (int i = 0; i < n; ) {
            if (isdigit(word[i])) {
                int j = i;
                while (j < n && isdigit(word[j])) {
                    j++;
                }
                while (i < j - 1 && word[i] == '0') {
                    i++;
                }
                s.insert(word.substr(i, j - i));
                i = j;
            } else {
                i++;
            }
        }
        
        return s.size();
    }
};
