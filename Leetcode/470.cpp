// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int a = rand7(), b = rand7();
        if (a > 4 && b < 4) return rand10();
        else return (a + b) % 10 + 1;
    }
};