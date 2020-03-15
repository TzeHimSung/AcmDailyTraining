// class Solution {
// public:
//     int px[4] {1, 0, -1, 0};
//     int py[4] {0, 1, 0, -1};

//     int n = 0, m = 0, ans = 0;
//     vector<vector<int>> vis;

//     int bfs(vector<vector<int>> &grid, int curX, int curY) {
//         queue<pair<int, int>>que;
//         que.push(make_pair(curX, curY));
//         int _size = 0;
//         while (que.size()) {
//             auto cur = que.front();
//             que.pop();
//             if (vis[cur.first][cur.second]) continue;
//             _size++;
//             vis[cur.first][cur.second] = 1;
//             for (int i = 0; i < 4; i++) {
//                 int newX = cur.first + px[i], newY = cur.second + py[i];
//                 if (newX >= 0 && newX < n && newY >= 0 && newY < m
//                         && grid[newX][newY] == 1 && !vis[newX][newY]) {
//                     que.push(make_pair(newX, newY));
//                 }
//             }
//         }
//         return _size;
//     }

//     int maxAreaOfIsland(vector<vector<int>> &grid) {
//         n = grid.size(), m = grid[0].size(), ans = 0;
//         vis = vector<vector<int>>(n, vector<int>(m, 0));

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (grid[i][j] == 1 && !vis[i][j]) {
//                     ans = max(ans, bfs(grid, i, j));
//                 }
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        function<int(int, int)>dfs = [&](int i, int j) {
            if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || grid[i][j] == 0) return 0;
            vis[i][j] = true;
            return 1 + dfs(i - 1, j) + dfs(i + 1, j) + dfs(i, j - 1) + dfs(i, j + 1);
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) ans = max(ans, dfs(i, j));
            }
        }

        return ans;
    }
};