class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int currSum = 0, maxAns = -INT_MAX;
        for (auto i : nums) {
            if (currSum <= 0) {
                currSum = i;
            } else {
                currSum += i;
            }
            maxAns = max(maxAns, currSum);
        }
        return maxAns;
    }
};