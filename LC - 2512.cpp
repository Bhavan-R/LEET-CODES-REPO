class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_set<string> pos(positive_feedback.begin(), positive_feedback.end());
        unordered_set<string> neg(negative_feedback.begin(), negative_feedback.end());
        
        int n = report.size();
        vector<pair<int, int>> scores;
        scores.reserve(n);
        
        for (int i = 0; i < n; ++i) {
            stringstream ss(report[i]);
            string word;
            int pts = 0;
            
            while (ss >> word) {
                if (pos.count(word)) {
                    pts += 3;
                } else if (neg.count(word)) {
                    pts -= 1;
                }
            }
            scores.push_back({pts, student_id[i]});
        }
        
        sort(scores.begin(), scores.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first != b.first) {
                return a.first > b.first;
            }
            return a.second < b.second;
        });
        
        vector<int> ans;
        ans.reserve(k);
        for (int i = 0; i < k; ++i) {
            ans.push_back(scores[i].second);
        }
        
        return ans;
    }
};
