class Solution {
public:
    bool canThreePartsEqualSum(vector<int> &A) {
        int sum = 0, n = A.size();
        for (auto i : A) sum += i;
        if (sum % 3) return false;
        sum /= 3;
        int i = 0, j = n - 1, tmp1 = A[0], tmp2 = A[n - 1];
        while (i + 1 < j) {
            if (tmp1 != sum) tmp1 += A[++i];
            if (tmp2 != sum) tmp2 += A[--j];
            if (tmp1 == tmp2 && tmp1 == sum && i + 1 < j) return true;
        }
        return false;
    }
};