#include <string>
#include <unordered_map>

class Solution {
public:
    std::string findValidPair(std::string s) {
        std::unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        for (int i = 0; i < s.length() - 1; ++i) {
            char first = s[i];
            char second = s[i + 1];

            if (first != second && 
                freq[first] == (first - '0') && 
                freq[second] == (second - '0')) {
                return string(1, first) + second;
            }
        }

        return "";
    }
};
