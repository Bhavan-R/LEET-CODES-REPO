#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<long long> dist(n * (k + 1), 1e18);
        using State = tuple<long long, int, int>;
        priority_queue<State, vector<State>, greater<State>> pq;

        dist[1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, count] = pq.top();
            pq.pop();

            if (u == n - 1) return d;
            if (d > dist[u * (k + 1) + count]) continue;

            for (auto& [v, w] : adj[u]) {
                int next_count = (labels[u] == labels[v]) ? count + 1 : 1;
                if (next_count <= k) {
                    int next_state = v * (k + 1) + next_count;
                    if (d + w < dist[next_state]) {
                        dist[next_state] = d + w;
                        pq.push({d + w, v, next_count});
                    }
                }
            }
        }

        return -1;
    }
};
