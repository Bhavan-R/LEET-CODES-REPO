#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        unordered_set<int> set3(nums3.begin(), nums3.end());

        int count[101] = {0};

        for (int num : set1) count[num]++;
        for (int num : set2) count[num]++;
        for (int num : set3) count[num]++;

        vector<int> result;
        for (int i = 1; i <= 100; ++i) {
            if (count[i] >= 2) {
                result.push_back(i);
            }
        }

        return result;
    }
};
