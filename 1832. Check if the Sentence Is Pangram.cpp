#include <unordered_set>
#include <string>

class Solution {
public:
    bool checkIfPangram(std::string sentence) {
        std::unordered_set<char> seen(sentence.begin(), sentence.end());
        return seen.size() == 26;
    }
};
