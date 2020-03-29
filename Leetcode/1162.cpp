class Solution {
public:
    int maxDistance(vector<vector<int>> &grid) {
        if (!grid.size()) return 0;
        queue<pair<int, int>>q;
        int rows = grid.size(), cols = grid[0].size(), land = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    q.push(make_pair(r, c));
                    grid[r][c] = -1;
                    land++;
                }
            }
        }
        if (!land || land == rows * cols) return -1;
        int step = 0, ans = 0;
        function<void(int, int)> solve = [&](int r, int c) {
            if (r >= rows || c >= cols || r < 0 || c < 0) return;
            if (grid[r][c] == 0) {
                ans = step;
                q.push(make_pair(r, c));
                grid[r][c] = -1;
            }
        };
        while (!q.empty()) {
            int size = q.size();
            step++;
            while (size--) {
                int r = q.front().first, c = q.front().second;
                q.pop();
                solve(r + 1, c), solve(r - 1, c), solve(r, c + 1), solve(r, c - 1);
            }
        }
        return ans;
    }
};