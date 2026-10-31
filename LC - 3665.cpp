class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int mod = 1e9 + 7;

        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(2, -2)));

        function<int(int, int, int)> f = [&](int x, int y, int d) -> int {
            if (x >= m || y >= n) return -1;

            if (grid[x][y] == 0)
                return x * n + y;

            int &v = memo[x][y][d];

            if (v != -2) return v;

            if (d == 0)
                v = f(x + 1, y, 1);
            else
                v = f(x, y + 1, 0);

            return v;
        };

        vector<vector<long long>> dp(m, vector<long long>(n, 0));

        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] == 0) continue;

                int a = f(i, j + 1, 0);
                int b = f(i + 1, j, 1);

                if (a != -1) {
                    int x = a / n;
                    int y = a % n;
                    dp[x][y] = (dp[x][y] + dp[i][j]) % mod;
                }

                if (b != -1) {
                    int x = b / n;
                    int y = b % n;
                    dp[x][y] = (dp[x][y] + dp[i][j]) % mod;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
