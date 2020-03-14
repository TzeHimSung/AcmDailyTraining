class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        if (nums.size() < 2) return;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                int pos = i + 1;
                for (int j = i + 1; j < nums.size(); j++) {
                    if (nums[j] > nums[i] && nums[j] < nums[pos])
                        pos = j;
                }
                swap(nums[i], nums[pos]);
                sort(nums.begin() + i + 1, nums.end());
                return;
            }
        }
        sort(nums.begin(), nums.end());
    }
};