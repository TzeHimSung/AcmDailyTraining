class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int curSum = 0, maxAns = -INT_MAX;
        for (auto i : nums) {
            if (curSum < 0) curSum = i;
            else curSum += i;
            maxAns = max(maxAns, curSum);
        }
        return maxAns;
    }
};