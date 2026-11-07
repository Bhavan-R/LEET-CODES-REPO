#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        using ServerPair = pair<int, int>;
        priority_queue<ServerPair, vector<ServerPair>, greater<ServerPair>> available;

        for (int i = 0; i < n; ++i) {
            available.push({servers[i], i});
        }

        using BusyTuple = tuple<long long, int, int>;
        priority_queue<BusyTuple, vector<BusyTuple>, greater<BusyTuple>> unavailable;

        vector<int> ans(m);
        long long current_time = 0;

        for (int i = 0; i < m; ++i) {
            current_time = max(current_time, (long long)i);

            if (available.empty()) {
                current_time = max(current_time, get<0>(unavailable.top()));
            }

            while (!unavailable.empty() && get<0>(unavailable.top()) <= current_time) {
                auto [free_time, weight, idx] = unavailable.top();
                unavailable.pop();
                available.push({weight, idx});
            }

            auto [weight, idx] = available.top();
            available.pop();

            ans[i] = idx;
            unavailable.push({current_time + tasks[i], weight, idx});
        }

        return ans;
    }
};
