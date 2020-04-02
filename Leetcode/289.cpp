class Solution {
public:
    void gameOfLife(vector<vector<int>> &board) {
        const int n = board.size();
        if (!n) return;
        const int m = board[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));

        function<void(int, int)> solve = [&](int x, int y) {
            int live = 0, dead = 0;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (i == j && !i) continue;
                    int px = i + x, py = j + y;
                    if (px < 0 || px >= n || py < 0 || py >= m) continue;
                    if (board[px][py]) live++;
                    else dead++;
                }
            }
            if (board[x][y]) {
                if (live < 2 || live > 3) ans[x][y] = 0;
                else ans[x][y] = 1;
            } else {
                if (live == 3) ans[x][y] = 1;
                else ans[x][y] = 0;
            }
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                solve(i, j);
            }
        }

        board = ans;
    }
};