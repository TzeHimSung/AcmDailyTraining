class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> ret;
        ret.push_back({});
        int size = nums.size();
        int k = pow(2, size), hash = 1;
        while (hash < k) {
            vector<int> cur;
            for (int i = 0; i < size; i++) {
                if ((1 << i)&hash) cur.push_back(nums[i]);
            }
            ret.push_back(cur);
            hash++;
        }
        return ret;
    }
};