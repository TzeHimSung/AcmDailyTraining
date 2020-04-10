class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<int>> vis(m, vector<int>(n, 0));

        function<int(int, int)> dfs = [&](int x, int y)->int{
            if (x < 0 || x >= m || y < 0 || y >= n || vis[x][y] || (x / 10 + x % 10 + y / 10 + y % 10) > k) {
                return 0;
            }
            vis[x][y] = 1;
            return dfs(x - 1, y) + dfs(x + 1, y) + dfs(x, y - 1) + dfs(x, y + 1) + 1;
        };

        return dfs(0, 0);
    }
};
