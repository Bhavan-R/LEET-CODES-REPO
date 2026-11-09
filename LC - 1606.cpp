class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> count(k, 0);
        set<int> available;
        for (int i = 0; i < k; ++i) {
            available.insert(i);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busy;

        for (int i = 0; i < arrival.size(); ++i) {
            int time = arrival[i];

            while (!busy.empty() && busy.top().first <= time) {
                available.insert(busy.top().second);
                busy.pop();
            }

            if (available.empty()) {
                continue;
            }

            int target = i % k;
            auto it = available.lower_bound(target);
            if (it == available.end()) {
                it = available.begin();
            }

            int server = *it;
            count[server]++;
            busy.push({time + load[i], server});
            available.erase(it);
        }

        int max_reqs = 0;
        for (int c : count) {
            max_reqs = max(max_reqs, c);
        }

        vector<int> result;
        for (int i = 0; i < k; ++i) {
            if (count[i] == max_reqs) {
                result.push_back(i);
            }
        }

        return result;
    }
};
