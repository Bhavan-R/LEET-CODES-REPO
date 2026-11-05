#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int> friend_set(friends.begin(), friends.end());
        vector<int> result;

        for (int id : order) {
            if (friend_set.count(id)) {
                result.push_back(id);
            }
        }

        return result;
    }
};
