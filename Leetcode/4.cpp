// class Solution {
// public:
//     double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
//         int len1 = nums1.size(), len2 = nums2.size();
//         if (len1 > len2) swap(nums1, nums2);
//         int p = 0, q = len1, half = len1 + len2 + 1 >> 1;
//         while (p <= q) {
//             int i = p + q >> 1, j = half - i;
//             if (i < q && nums2[j - 1] > nums1[i])
//                 p = i + 1;
//             else if (i > p && nums1[i - 1] > nums2[j])
//                 q = i - 1;
//             else {
//                 int maxLeft = 0;
//                 if (!i) maxLeft = nums2[j - 1];
//                 else if (!j) maxLeft = nums1[i - 1];
//                 else maxLeft = max(nums1[i - 1], nums2[j - 1]);
//                 if ((len1 + len2) & 1) return maxLeft;
//                 int minRight = 0;
//                 if (i == len1) minRight = nums2[j];
//                 else if (j == len2) minRight = nums1[i];
//                 else minRight = min(nums1[i], nums2[j]);
//                 return (double(maxLeft) + double(minRight)) / 2.0;
//             }
//         }
//         return 0.0;
//     }
// };

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size(), n = nums2.size();
        int left = n + m + 1 >> 1, right = n + m + 2 >> 1;
        return (solve(nums1, 0, nums2, 0, left) + solve(nums1, 0, nums2, 0, right)) / 2.0;
    }

    double solve(vector<int> &nums1, int i, vector<int> &nums2, int j, int k) {
        if (i >= nums1.size()) return nums2[j + k - 1];
        if (j >= nums2.size()) return nums1[i + k - 1];
        if (k == 1) return min(nums1[i], nums2[j]);
        int midVal_1 = (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1] : INT_MAX;
        int midVal_2 = (j + k / 2 - 1 < nums2.size()) ? nums2[j + k / 2 - 1] : INT_MAX;
        if (midVal_1 < midVal_2) return solve(nums1, i + k / 2, nums2, j, k - k / 2);
        else return solve(nums1, i, nums2, j + k / 2, k - k / 2);
    }
};