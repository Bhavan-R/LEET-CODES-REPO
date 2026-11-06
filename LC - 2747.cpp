#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    std::vector<int> countServers(int n, std::vector<std::vector<int>>& logs, int x, std::vector<int>& queries) {
        int qLen = queries.size();
        std::vector<int> ans(qLen);

        // Sort logs by time
        std::sort(logs.begin(), logs.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];
        });

        // Store query values along with their original indices and sort by time
        std::vector<std::pair<int, int>> sortedQueries(qLen);
        for (int i = 0; i < qLen; ++i) {
            sortedQueries[i] = {queries[i], i};
        }
        std::sort(sortedQueries.begin(), sortedQueries.end());

        std::vector<int> serverCount(n + 1, 0);
        int activeServers = 0;
        int left = 0, right = 0;
        int logCount = logs.size();

        for (const auto& [qTime, originalIdx] : sortedQueries) {
            int startTime = qTime - x;

            // Expand window right edge: include all requests up to qTime
            while (right < logCount && logs[right][1] <= qTime) {
                int serverId = logs[right][0];
                if (serverCount[serverId] == 0) {
                    activeServers++;
                }
                serverCount[serverId]++;
                right++;
            }

            // Shrink window left edge: remove requests before startTime
            while (left < logCount && logs[left][1] < startTime) {
                int serverId = logs[left][0];
                serverCount[serverId]--;
                if (serverCount[serverId] == 0) {
                    activeServers--;
                }
                left++;
            }

            // Store result for original query index
            ans[originalIdx] = n - activeServers;
        }

        return ans;
    }
};
