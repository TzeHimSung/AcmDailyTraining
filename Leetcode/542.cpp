class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
        int n = matrix.size(), m = matrix[0].size();
        queue<pair<int, int>>q;
        while (q.size()) q.pop();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!matrix[i][j]) {
                    q.push(make_pair(i, j));
                } else {
                    matrix[i][j] = n + m;
                }
            }
        }

        const int px[] = {-1, 0, 1, 0}, py[] = {0, 1, 0, -1};

        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = px[i] + curr.first, ny = py[i] + curr.second;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny] > matrix[curr.first][curr.second] + 1) {
                    matrix[nx][ny] = matrix[curr.first][curr.second] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
        return matrix;
    }
};