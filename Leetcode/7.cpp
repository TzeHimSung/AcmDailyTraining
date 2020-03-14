class Solution {
public:
    int reverse(int x) {
        long long rs = 0;
        long long maxx = (1LL << 31) - 1, minn = -(1LL << 31);
        for (; x; rs = rs * 10 + x % 10, x /= 10);
        return (rs > maxx || rs < minn) ? 0 : rs;
    }
};