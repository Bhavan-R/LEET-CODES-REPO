class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int maxTime = events[0][1];
        int ansIndex = events[0][0];

        for (int i = 1; i < events.size(); i++) {
            int timeTaken = events[i][1] - events[i - 1][1];

            if (timeTaken > maxTime) {
                maxTime = timeTaken;
                ansIndex = events[i][0];
            } else if (timeTaken == maxTime) {
                ansIndex = min(ansIndex, events[i][0]);
            }
        }

        return ansIndex;
    }
};
