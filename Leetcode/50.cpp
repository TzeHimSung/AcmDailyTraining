class Solution {
public:
    double myPow(double x, int n) {
        double ret = 1.0;
        int i = n;
        while (i) {
            if (i & 1) ret *= x;
            x *= x;
            i /= 2;
        }
        return n < 0 ? 1.0 / ret : ret;
    }
};