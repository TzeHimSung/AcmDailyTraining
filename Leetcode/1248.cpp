class Solution {
public:
    int numberOfSubarrays(vector<int> &nums, int k) {
        vector<int> cnt(nums.size() + 1, 0);
        int currSum = 0, ans = 0;
        cnt[0] = 1;
        for (auto x : nums) {
            currSum += x & 1;
            cnt[currSum]++;
            if (currSum >= k) ans += cnt[currSum - k];
        }
        return ans;
    }
};
