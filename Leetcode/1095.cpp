/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int l = 0, r = n - 1;

        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (mountainArr.get(mid) > mountainArr.get(mid - 1)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        int top_idx = l;
        l = 0, r = top_idx;

        while (l < r) {
            int mid = (l + r) >> 1;
            if (mountainArr.get(mid) >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        if (mountainArr.get(l) == target) {
            return l;
        }

        l = top_idx, r = n - 1;

        while (l < r) {
            int mid = (l + r) >> 1;
            if (mountainArr.get(mid) <= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        if (mountainArr.get(l) == target) {
            return l;
        }

        return -1;
    }
};