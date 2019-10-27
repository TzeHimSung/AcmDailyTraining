class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        if (len1 > len2) swap(nums1, nums2);
        int p = 0, q = len1, half = len1 + len2 + 1 >> 1;
        while (p <= q) {
            int i = p + q >> 1, j = half - i;
            if (i < q && nums2[j - 1] > nums1[i])
                p = i + 1;
            else if (i > p && nums1[i - 1] > nums2[j])
                q = i - 1;
            else {
                int maxLeft = 0;
                if (!i) maxLeft = nums2[j - 1];
                else if (!j) maxLeft = nums1[i - 1];
                else maxLeft = max(nums1[i - 1], nums2[j - 1]);
                if ((len1 + len2) & 1) return maxLeft;
                int minRight = 0;
                if (i == len1) minRight = nums2[j];
                else if (j == len2) minRight = nums1[i];
                else minRight = min(nums1[i], nums2[j]);
                return (double(maxLeft) + double(minRight)) / 2.0;
            }
        }
        return 0.0;
    }
};