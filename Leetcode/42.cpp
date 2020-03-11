class Solution {
public:
    int trap(vector<int> &height) {
        int n = height.size();
        vector<int>pre(n), suf(n);
        for (int i = 1; i < n; i++) pre[i] = max(pre[i - 1], height[i - 1]);
        for (int i = n - 2; i >= 0; i--) suf[i] = max(suf[i + 1], height[i + 1]);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int level = min(pre[i], suf[i]);
            ans += max(0, level - height[i]);
        }
        return ans;
    }
};