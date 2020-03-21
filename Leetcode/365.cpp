class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (!z) return true;
        if (x + y < z) return false;
        if (x > y) swap(x, y);
        if (!x) return y == z;
        return !(z % __gcd(x, y));
    }
};