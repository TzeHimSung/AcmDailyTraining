class Solution {
public:
    vector<int> sortArray(vector<int> &nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void quickSort(vector<int> &nums, int curl, int curr) {
        int mid = nums[(curl + curr) >> 1];
        int l = curl, r = curr;
        do {
            while (nums[l] < mid) l++;
            while (nums[r] > mid) r--;
            if (l <= r) {
                swap(nums[l], nums[r]);
                l++, r--;
            }
        } while (l <= r);
        if (curl < r) quickSort(nums, curl, r);
        if (l < curr) quickSort(nums, l, curr);
    }
};
