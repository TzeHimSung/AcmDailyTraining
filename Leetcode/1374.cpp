class Solution {
public:
    string generateTheString(int n) {
        string ret = "";
        for (int i = 1; i <= n; i++) ret += 'a';
        if (!(n & 1)) ret[0] = 'b';
        return ret;
    }
};