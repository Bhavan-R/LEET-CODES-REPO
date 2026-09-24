#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>

class Solution {
public:
    int rearrangeCharacters(std::string s, std::string target) {
        std::unordered_map<char, int> s_count, target_count;
        
        for (char c : s) {
            s_count[c]++;
        }
        for (char c : target) {
            target_count[c]++;
        }
        
        int min_copies = INT_MAX;
        
        for (auto& [ch, req] : target_count) {
            int avail = s_count[ch];
            min_copies = std::min(min_copies, avail / req);
        }
        
        return min_copies;
    }
};
