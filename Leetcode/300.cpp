// O(n^2)
// class Solution {
// public:
//     int lengthOfLIS(vector<int> &nums) {
//         int ans = nums.size() ? 1 : 0;
//         vector<int>dp(nums.size() + 1, 1);
//         for (int i = 0; i < nums.size(); i++) {
//             for (int j = 0; j < i; j++) {
//                 if (nums[j] < nums[i]) {
//                     dp[i] = max(dp[i], dp[j] + 1);
//                 }
//                 ans = max(ans, dp[i]);
//             }
//         }
//         return ans;
//     }
// };

// O(nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        vector<int>dp(nums.size(), 0);
        int ans = 0;
        for (auto num : nums) {
            int l = 0, r = ans;
            while (l < r) {
                // 在dp数组中二分出合适的插入位置
                int mid = l + (r - l) / 2;
                if (dp[mid] < num) l = mid + 1;
                else r = mid;
            }
            dp[l] = num;
            // 如果插入到最后一个位置就要更新长度
            if (l == ans) ans++;
        }
        return ans;
    }
};