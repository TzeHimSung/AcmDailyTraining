// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>> &intervals) {
//         vector<vector<int>> ret{};
//         if (intervals.size() == 0) return ret;
//         sort(intervals.begin(), intervals.end());
//         int curl = -1, curr = -1;
//         for (int i = 0; i < intervals.size() - 1; i++) {
//             if (curl == -1) {
//                 curl = intervals[i][0], curr = intervals[i][1];
//             }
//             if (curr >= intervals[i + 1][0]) {
//                 curr = max(curr, intervals[i + 1][1]);
//             } else {
//                 ret.push_back(vector<int> {curl, curr});
//                 curl = curr = -1;
//             }
//         }
//         if (curl == -1) {
//             ret.push_back(intervals[intervals.size() - 1]);
//         } else {
//             ret.push_back(vector<int> {curl, curr});
//         }
//         return ret;
//     }
// };

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        vector<vector<int>> ret{};
        sort(intervals.begin(), intervals.end());
        for (auto i : intervals) {
            if (ret.empty() || i[0] > ret.back()[1]) ret.push_back(i);
            else ret.back()[1] = max(ret.back()[1], i[1]);
        }
        return ret;
    }
};