#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int a : nums) {
            freq[a]++;
        }

        vector<int> b;
        for (const auto& [c, d] : freq) {
            b.push_back(c);
        }
        sort(b.begin(), b.end());

        int e = b.size();
        for (int f = 0; f < e; ++f) {
            for (int g = f + 1; g < e; ++g) {
                int h = b[f];
                int i = b[g];
                if (freq[h] != freq[i]) {
                    return {h, i};
                }
            }
        }

        return {-1, -1};
    }
};
