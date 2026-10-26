class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        int r = 0, c = cols - 1;

        while (r < rows && c >= 0) {
            if (grid[r][c] < 0) {
                count += (rows - r);
                c--; 
            } else {
                r++; 
            }
        }

        return count;
    }
};
