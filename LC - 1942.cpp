class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size(), c = 0;
        vector<array<int, 3>> v(n);
        for (int i = 0; i < n; ++i) v[i] = {times[i][0], times[i][1], i};
        sort(v.begin(), v.end());
        
        priority_queue<int, vector<int>, greater<int>> a;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> o;
        
        for (auto& x : v) {
            while (!o.empty() && o.top().first <= x[0]) {
                a.push(o.top().second);
                o.pop();
            }
            int s;
            if (!a.empty()) {
                s = a.top();
                a.pop();
            } else {
                s = c++;
            }
            if (x[2] == targetFriend) return s;
            o.push({x[1], s});
        }
        return -1;
    }
};
