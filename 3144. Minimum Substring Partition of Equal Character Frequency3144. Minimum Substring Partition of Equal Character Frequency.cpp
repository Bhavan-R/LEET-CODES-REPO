class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        int n = s.length();
        vector<int> dp(n + 1, n);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            vector<int> count(26, 0);
            int maxFreq = 0, unique = 0;

            for (int j = i; j >= 1; j--) {
                if (count[s[j - 1] - 'a'] == 0) unique++;
                count[s[j - 1] - 'a']++;
                maxFreq = max(maxFreq, count[s[j - 1] - 'a']);

                if (maxFreq * unique == i - j + 1) {
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        return dp[n];
    }
};class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        int n = s.length();
        vector<int> dp(n + 1, n);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            vector<int> count(26, 0);
            int maxFreq = 0, unique = 0;

            for (int j = i; j >= 1; j--) {
                if (count[s[j - 1] - 'a'] == 0) unique++;
                count[s[j - 1] - 'a']++;
                maxFreq = max(maxFreq, count[s[j - 1] - 'a']);

                if (maxFreq * unique == i - j + 1) {
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        return dp[n];
    }
};
