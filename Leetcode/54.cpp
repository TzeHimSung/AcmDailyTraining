class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int>ret{};
        if ((int)matrix.size() == 0) return ret;
        vector<vector<bool>> vis((int)matrix.size(), vector<bool>((int)matrix[0].size(), false));
        int x = 0, y = 0, dx = 0, dy = 1;
        for (int cnt = 0; cnt < (int)matrix.size() * (int)matrix[0].size(); cnt++) {
            ret.push_back(matrix[x][y]);
            vis[x][y] = true;
            if (x + dx < 0 || x + dx >= (int)matrix.size() || y + dy < 0 || y + dy >= (int)matrix[0].size() || vis[x + dx][y + dy]) {
                if (dx == 0 && dy == 1) dx = 1, dy = 0;
                else if (dx == 1 && dy == 0) dx = 0, dy = -1;
                else if (dx == 0 && dy == -1) dx = -1, dy = 0;
                else dx = 0, dy = 1;
            }
            x += dx, y += dy;
        }
        return ret;
    }
};