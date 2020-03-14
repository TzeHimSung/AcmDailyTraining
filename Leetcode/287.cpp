class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int p1 = 0, p2 = 0;
        do {
            p1 = nums[p1];
            p2 = nums[nums[p2]];
        } while (p1 != p2);
        p2 = 0;
        do {
            p1 = nums[p1];
            p2 = nums[p2];
        } while (p1 != p2);
        return p1;
    }
};