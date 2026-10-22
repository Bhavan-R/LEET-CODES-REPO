#include <vector>

class Solution {
public:
    std::vector<int> findMissingAndRepeatedValues(std::vector<std::vector<int>>& grid) {
        long long n = grid.size();
        long long N = n * n;
        
        long long actualSum = 0;
        long long actualSqSum = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                long long val = grid[i][j];
                actualSum += val;
                actualSqSum += val * val;
            }
        }
        
        long long expectedSum = N * (N + 1) / 2;
        long long expectedSqSum = N * (N + 1) * (2 * N + 1) / 6;
        
        long long diffSum = actualSum - expectedSum;
        long long diffSqSum = actualSqSum - expectedSqSum;
        
        long long sumPlus = diffSqSum / diffSum;
        
        int a = (diffSum + sumPlus) / 2;
        int b = (sumPlus - diffSum) / 2;
        
        return {a, b};
    }
};
