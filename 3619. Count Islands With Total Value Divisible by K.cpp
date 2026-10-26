class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;

        auto dfs = [&](auto& self, int r, int c) -> long long {
            long long sum = grid[r][c];
            grid[r][c] = 0;
            
            int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
            int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
            
            for (int i = 0; i < 8; ++i) {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > 0) {
                    sum += self(self, nr, nc);
                }
            }
            return sum;
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    if (dfs(dfs, i, j) % k == 0) count++;
                }
            }
        }
        return count;
    }
};
