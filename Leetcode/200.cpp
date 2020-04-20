class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        const int n = grid.size();
        if (!n) return 0;
        const int m = grid[0].size();
        if (!m) return 0;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        function<void(int, int)> dfs = [&](int curx, int cury) {
            if (curx < 0 || curx >= n || cury < 0 || cury >= m || grid[curx][cury] == '0' || vis[curx][cury] == 1) {
                return;
            }
            vis[curx][cury] = 1;
            dfs(curx + 1, cury), dfs(curx - 1, cury), dfs(curx, cury + 1), dfs(curx, cury - 1);
        };

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && vis[i][j] == 0) {
                    dfs(i, j);
                    ans++;
                }
            }
        }

        return ans;
    }
};
