class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int>ret(2, -1);
        if (nums.size() < 1) return ret;
        int n = nums.size(), l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] < target) l = mid + 1;
            else r = mid;
        }
        if (nums[l] != target) return ret;
        ret[0] = l;
        r = n;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] < target + 1) l = mid + 1;
            else r = mid;
        }
        ret[1] = l - 1;
        return ret;
    }
};