#include <vector>

class Solution {
public:
    int arraySign(std::vector<int>& nums) {
        int negative_count = 0;

        for (int num : nums) {
            if (num == 0) {
                return 0;
            }
            if (num < 0) {
                negative_count++;
            }
        }

        return (negative_count % 2 == 0) ? 1 : -1;
    }
};
