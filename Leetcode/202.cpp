class Solution {
public:
    bool isHappy(int n) {
        set<int>s;
        s.clear();
        while (s.find(n) == s.end()) {
            int sum = 0;
            s.insert(n);

            while (n) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }

            n = sum;
        }
        return n == 1;
    }
};