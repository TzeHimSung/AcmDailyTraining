class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int ret = 0;
        for (auto i : nums) ret ^= i;
        return ret;
    }
};