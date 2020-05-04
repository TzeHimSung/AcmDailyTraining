class Solution {
public:
    int jump(vector<int> &nums) {
        if (nums.size() == 1) return 0;
        int reach = 0, nextReach = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            nextReach = max(nums[i] + i, nextReach);
            if (nextReach >= nums.size() - 1) {
                return ans + 1;
            }
            if (i == reach) {
                ans++;
                reach = nextReach;
            }
        }
        return ans;
    }
};