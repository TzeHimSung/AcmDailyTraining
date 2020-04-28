class Solution {
public:
    vector<int> singleNumbers(vector<int> &nums) {
        int sum = 0;
        for (auto num : nums)
            sum ^= num;
        vector<int> ans(2, 0);
        int flag = sum & (-sum);
        for (auto num : nums) {
            if (!(num & flag))
                ans[0] ^= num;
            else
                ans[1] ^= num;
        }
        return ans;
    }
};