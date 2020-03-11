class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
        if (matrix.size() == 0) return false;
        int curX = 0, curY = matrix[0].size() - 1;
        while (curX < matrix.size() && curY >= 0) {
            if (matrix[curX][curY] == target) return true;
            else if (matrix[curX][curY] < target) curX++;
            else curY--;
        }
        return false;
    }
};