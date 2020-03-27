class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
        vector<int>sorted = nums;
        sort(sorted.begin(), sorted.end());
        vector<int>ret;
        for (auto num : nums) {
            int count = lower_bound(sorted.begin(), sorted.end(), num) - sorted.begin();
            ret.push_back(count);
        }
        return ret;
    }
};
