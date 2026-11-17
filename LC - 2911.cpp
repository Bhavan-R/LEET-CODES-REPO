class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        
        vector<vector<int>> v(n + 1);
        for (int l = 2; l <= n; ++l) {
            for (int d = 1; d < l; ++d) {
                if (l % d == 0) {
                    v[l].push_back(d);
                }
            }
        }
        
        vector<vector<int>> c(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int l = j - i + 1;
                for (int d : v[l]) {
                    int m = 0;
                    for (int g = 0; g < d; ++g) {
                        int a = i + g;
                        int b = j - (d - 1 - g);
                        while (a < b) {
                            if (s[a] != s[b]) {
                                m++;
                            }
                            a += d;
                            b -= d;
                        }
                    }
                    c[i][j] = min(c[i][j], m);
                }
            }
        }
        
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1e9));
        dp[0][0] = 0;
        
        for (int p = 1; p <= k; ++p) {
            for (int i = 2 * p; i <= n; ++i) {
                for (int j = 2 * (p - 1); j <= i - 2; ++j) {
                    dp[i][p] = min(dp[i][p], dp[j][p - 1] + c[j][i - 1]);
                }
            }
        }
        
        return dp[n][k];
    }
};
