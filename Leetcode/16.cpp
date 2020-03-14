class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        int delta = INT_MAX, sum = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int currSum = nums[i] + nums[j] + nums[k];
                int currDelta = abs(target - currSum);
                if (currDelta < delta) {
                    delta = currDelta;
                    sum = currSum;
                }
                if (currSum > target) k--;
                else j++;
            }
        }
        return sum;
    }
};