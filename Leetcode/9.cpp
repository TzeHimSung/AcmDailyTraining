class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        string s = "";
        for (; x; s += (char)(x % 10 + '0'), x /= 10);
        string tmp = s;
        reverse(tmp.begin(), tmp.end());
        return s == tmp;
    }
};