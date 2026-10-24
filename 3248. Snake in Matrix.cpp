class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int row = 0, col = 0;
        for (const string& cmd : commands) {
            if (cmd == "UP") {
                row--;
            } else if (cmd == "DOWN") {
                row++;
            } else if (cmd == "LEFT") {
                col--;
            } else if (cmd == "RIGHT") {
                col++;
            }
        }
        return (row * n) + col;
    }
};
