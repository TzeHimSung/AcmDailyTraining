class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> ret;
        ret.clear();
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            if (nums[l] > 0) break;
            if (l > 0 && nums[l] == nums[l - 1]) {
                l++; continue;
            }
            for (int i = l + 1; i < r; i++) {
                if (i > (l + 1) && nums[i] == nums[i - 1]) continue;
                int sum = nums[l] + nums[i] + nums[r];
                if (!sum) ret.push_back(vector<int> {nums[l], nums[i], nums[r]});
                else if (sum > 0) r--, i--;
            }
            l++;
            r = nums.size() - 1;
        }
        return ret;
    }
};