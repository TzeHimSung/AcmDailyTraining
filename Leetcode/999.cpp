class Solution {
public:
    int numRookCaptures(vector<vector<char>> &board) {
        // find car position
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'R') {
                    return solve(board, i, j, 0, 1) + solve(board, i, j, 0, -1) + solve(board, i, j, 1, 0) + solve(board, i, j, -1, 0);
                }
            }
        }
        return 0;
    }

    int solve(vector<vector<char>> &board, int x, int y, int dx, int dy) {
        while (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && board[x][y] != 'B') {
            if (board[x][y] == 'p') return 1;
            x += dx, y += dy;
        }
        return 0;
    }
};
