class Solution {
public:
    int mySqrt(int x) {
        using ll = long long;
        ll l = 0, r = INT_MAX, a = x;
        while (l <= r) {
            ll mid = l + (r - l) / 2;
            if (mid * mid <= x) l = mid + 1;
            else r = mid - 1;
        }
        return r;
    }
};